//
//  DateTimePickerViewController.h
//  DateTimePicker
//
//  Created by Anupam Mishra on 02/02/16.
//  Copyright © 2016 anupam. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    QuitWithResult, //When confirm button is pressed
    QuitWithBackButton, //When back button is pressed
    QuitWithCancel, //when View outside date picker is pressed
} DatePickerQuitMethod;

typedef enum : NSUInteger {
    StepOneMinute = 1,
    StepTwoMinutes = 2,
    StepFiveMinutes = 5,
    StepTenMinutes = 10,
    StepFifteenMinutes = 15,
    StepHalfAnHour = 30,
} DatePickerMinutesStep;


typedef enum : NSUInteger {
    DateType = 1, //When date button is pressed
    TimeType = 2, //When time button is pressed
    DateTimeType = 3, //when date picker is pressed
} DatePickerSelectedType;



/**
 *  Implement this protocol to take results from DatePickerViewController
 */
@protocol DatePickerViewControllerDelegate <NSObject>
/**
 *  This method is called when user touch confrim button.
 *
 *  @param date selected date and time
 */
- (void)DatePickerPickedDate:(NSDate *)date;
@optional
/**
 *  This method is called when view will be dismissed.
 *
 *  @param method of quit the view.
 */
- (void)DatePickerWillDismissWithQuitMethod:(DatePickerQuitMethod)method;
/**
 *  This method is called when view is dismissed.
 *
 *  @param method of quit the view.
 */
- (void)DatePickerDidDismissWithQuitMethod:(DatePickerQuitMethod)method;

@end

/**
 *  Main class. Show it as modal view controller. All parameters below are optional, but remember to set choosed ones before call presentViewController.
 */
@interface DateTimePickerViewController : UIViewController
/**
 *  Register your delegate here
 */
@property (nonatomic, weak) id<DatePickerViewControllerDelegate> delegate;
/**
 *  Indidcate that ViewController should be dismiss when there is touch outside date picker. Default is YES.
 */
@property (nonatomic, assign, getter=shouldDismissOnCancelTouch) BOOL dismissOnCancelTouch;
/**
 *  Minute picker step value. Default StepFiveMinutes
 */
@property (nonatomic, assign) DatePickerMinutesStep minuteStep;

@property (nonatomic,assign) DatePickerSelectedType selectedtype;
/**
 *  Color of interface elements
 */
@property (nonatomic, strong) UIColor *mainColor;
/**
 *  Selected date. Warning! Don't read selected date from this variable. User NSDatePickerViewControllerDelegate protocol instead.
 */
@property (nonatomic, strong) NSDate *date;
/**
 *  Minimum avaiable date on picker
 */
@property (nonatomic, strong) NSDate *minDate;
/**
 *  Maximum avaiable date on picker
 */
@property (nonatomic, strong) NSDate *maxDate;
/**
 *  Formater for date in picker. Default format is "ccc d MMM"
 */
@property (nonatomic, strong) NSDateFormatter *dateFormatter;
/**
 *  Format month and date label above date picker. Default format is "MMMM yyyy"
 */
@property (nonatomic, strong) NSDateFormatter *monthAndYearLabelDateFormater;
/**
 *  Title of picker confirm button
 */
@property (nonatomic, strong) NSString *confirmButtonTitle;
/**
 *  Back button title
 */
@property (nonatomic, strong) NSString *backButtonTitle;

@end
