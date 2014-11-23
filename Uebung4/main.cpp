#include "common.h"
#include "NucleicAcid.h"
#include "Alignment.h"
#include "console_color.h"

int testAlignment();

void usage()
{
    std::cout << "Usage: alignm <SEQ1> <SEQ2>" << std::endl << std::endl;
}

int main(int argc, char *argv[])
{
    DO_TEST
    {
        std::cout <<"-- Compiled with -DSELFTEST --" << std::endl;
        int fail;

        fail = testAlignment();

        if(fail)
            std::cout << "-- Self test FAILED! --" << std::endl << std::endl;
        else
            std::cout << "-- Self test successful. --" << std::endl << std::endl;
    }

    //const char *a = argc >= 2 ? argv[1] : "AAATT";
    //const char *b = argc >= 3 ? argv[2] : "AGATTTT";

    //std::cout << Colorizer(Console::WHITE, Console::LRED) << a << std::endl << b << Colorizer() << std::endl;
    // alignm AAATTTTGGGTTTGGGCCCCCC AAGTTTGGGTATGGCCCCCCAAAA
    // alignm AAATTTTGGGTTTGGGCCCCAAA AAGTTTGGGTATGGCCCCCCAAAA

    if(argc < 3)
    {
        usage();
        return 0;
    }

    NucleicAcid sa(argv[1]);
    NucleicAcid sb(argv[2]);
    Alignment<Similarity> al;
    al.setSequence1(sa);
    al.setSequence2(sb);
    al.computeGlobalAlignment();

    al.visualize(std::cout, 2, true);
    al.print(std::cout, true);

    return 0;
}


int testAlignment()
{
    // smoke tests, basic things
    {
         Alignment<EditDistance> ali;
         ASSERT(ali == ali);

         // these must not segfault
         const StringPair& sp1 = ali.getAlignment();
         ali.computeGlobalAlignment();
         const StringPair& sp2 = ali.getAlignment();
         ASSERT(sp1.first == sp1.second);
         ASSERT(sp2.first == sp2.second);
         ASSERT(sp1 == sp2);
    }

    // basic things, assignment, copy ctor
    {
        Alignment<EditDistance> ali("A","A");
        ASSERT(ali.getSequence1().getString() == "A");
        ASSERT(ali.getSequence2().getString() == "A");
        ali.computeGlobalAlignment();
        ASSERT(ali.getAlignment().first == ali.getAlignment().second);

        Alignment<EditDistance> bli, oli(ali);

        ASSERT(ali != bli);
        ASSERT(ali == oli);

        bli = ali;
        ASSERT(bli == oli); // because ali == oli

        Sequence n("T");
        ali.setSequence1(n);
        ASSERT(ali.getSequence1().getString() == "T");
        ASSERT(ali.getSequence2().getString() == "A");

        ali.setSequence2(n);
        ASSERT(ali.getSequence1().getString() == "T");
        ASSERT(ali.getSequence2().getString() == "T");
        ASSERT(ali != bli); // bli must not have changed
    }

    {
        Alignment<EditDistance> ali("TAT","TT"); // insertion/deletion (one way)
        ali.computeGlobalAlignment();
        ASSERT(ali.getAlignment().first == "TAT");
        ASSERT(ali.getAlignment().second == "T-T");
    }

    {
        Alignment<EditDistance> ali("TT","TAT"); // insertion/deletion (other way)
        ali.computeGlobalAlignment();
        ASSERT(ali.getAlignment().first == "T-T");
        ASSERT(ali.getAlignment().second == "TAT");
    }

    {
        Alignment<EditDistance> ali("TATAGGACCA","TTAGACGCA"); // hand made, non-ambigous test for both sides
        ali.computeGlobalAlignment();
        ASSERT(ali.getAlignment().first  == "TATAGGAC-CA");
        ASSERT(ali.getAlignment().second == "T-TAG-ACGCA");
    }

    {
        Alignment<EditDistance> ali("ATGGGGGGAT","ATAT"); // hand made, non-ambigous test with a larger gap
        ali.computeGlobalAlignment();
        ASSERT(ali.getAlignment().first  == "ATGGGGGGAT");
        ASSERT(ali.getAlignment().second == "AT------AT");

        // copy ctor
        {
            Alignment<EditDistance> oli(ali);
            std::stringstream ss, ss2;
            oli.print(ss);
            ASSERT(ss.str().length() > 10); // exact string matching is useless here, just be sure enough was printed, and not just newlines
            oli.visualize(ss2);
            ASSERT(ss2.str().length() > 30);
        }

        // assignment
        {
            Alignment<EditDistance> oli;
            oli = ali;
            std::stringstream ss, ss2;
            oli.print(ss);
            ASSERT(ss.str().length() > 10); // exact string matching is useless here, just be sure enough was printed, and not just newlines
            oli.visualize(ss2);
            ASSERT(ss2.str().length() > 40);
        }

        Sequence empty;
        ali.setSequence1(empty);
        ali.computeGlobalAlignment(); // must not change anything, because sequence 1 is empty now
        ASSERT(ali.getAlignment().first  == "ATGGGGGGAT");
        ASSERT(ali.getAlignment().second == "AT------AT");

        Sequence n("ATCAT");
        ali.setSequence1(n);
        ali.computeGlobalAlignment();
        ASSERT(ali.getAlignment().first  == "ATCAT");
        ASSERT(ali.getAlignment().second == "AT-AT");
    }

    // backtracking test
    {
        Alignment<EditDistance> ali("T", "AAAAAAAAAAAAAAA");
        ali.computeGlobalAlignment(); // should not blow up
        ASSERT(ali.getAlignment().first.length() == ali.getSequence2().getString().length());
    }

    // backtracking test, swapped
    {
        Alignment<EditDistance> ali("TTTTTTTTTTTT", "A");
        ali.computeGlobalAlignment(); // should not blow up
        ASSERT(ali.getAlignment().second.length() == ali.getSequence1().getString().length());
    }



    return 0;
}
