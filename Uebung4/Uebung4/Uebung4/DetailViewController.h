//
//  DetailViewController.h
//  Uebung4
//
//  Created by Eva on 23.11.14.
//  Copyright (c) 2014 Eva. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController

@property (strong, nonatomic) id detailItem;
@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@end

