//
//  ViewController.m
//  DateTimePicker
//
//  Created by Anupam Mishra on 02/02/16.
//  Copyright © 2016 anupam. All rights reserved.
//

#import "ViewController.h"
#import "DateTimePickerViewController.h"

@interface ViewController ()<DatePickerViewControllerDelegate>
@property (strong, nonatomic) IBOutlet UILabel *selectedDateLabel;
@property (nonatomic, strong) NSDate *selectedDate;

@property (strong, nonatomic) DateTimePickerViewController *vc ;

- (IBAction)getTimeButtonTouchUpInside:(id)sender;
- (IBAction)getDateTimeButtonTouchUpInside:(id)sender;
- (IBAction)getDateButtonTouchUpInside:(id)sender;


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - action to pick date time

- (IBAction)getDateTimeButtonTouchUpInside:(id)sender
{
   self.vc = [DateTimePickerViewController new];
    self.vc.delegate = self;
    self.vc.selectedtype = DateTimeType;
    if (self.selectedDate)
    {
        self.vc.date = self.selectedDate;
    }
    [self presentViewController:self.vc animated:YES completion:nil];
}

- (IBAction)getDateButtonTouchUpInside:(id)sender
{
    self.vc = [DateTimePickerViewController new];
    self.vc.delegate = self;
    self.vc.selectedtype = DateType;
    if (self.selectedDate)
    {
        self.vc.date = self.selectedDate;
    }
    [self presentViewController:self.vc animated:YES completion:nil];
}

- (IBAction)getTimeButtonTouchUpInside:(id)sender {
    
    self.vc = [DateTimePickerViewController new];
    self.vc.delegate = self;
    self.vc.selectedtype = TimeType;
    if (self.selectedDate)
    {
        self.vc.date = self.selectedDate;
    }
    [self presentViewController:self.vc animated:YES completion:nil];
}

- (void)DatePickerPickedDate:(NSDate *)date
{
    NSLog(@"Date picked %@", date);
    NSDateFormatter *dateFormater = [NSDateFormatter new];
    if (self.vc.selectedtype == DateTimeType)
    {
        dateFormater.dateFormat = @"yyyy.MM.dd HH:mm:ss";
        self.selectedDateLabel.text = [dateFormater stringFromDate:date];
    }
    if (self.vc.selectedtype == TimeType)
    {
        dateFormater.dateFormat = @"HH:mm:ss";
        self.selectedDateLabel.text = [dateFormater stringFromDate:date];
    }
    if (self.vc.selectedtype == DateType)
    {
        [dateFormater setDateFormat:@"EEE MM YYYY"];
        self.selectedDateLabel.text = [dateFormater stringFromDate:date];
    }
    
    self.selectedDate = date;
}


//optional
- (void)DatePickerDidDismissWithQuitMethod:(DatePickerQuitMethod)method {
    NSLog(@"Picker did dismiss with %lu", method);
}

//optional
- (void)DatePickerWillDismissWithQuitMethod:(DatePickerQuitMethod)method {
    NSLog(@"Picker will dismiss with %lu", method);
}


@end
