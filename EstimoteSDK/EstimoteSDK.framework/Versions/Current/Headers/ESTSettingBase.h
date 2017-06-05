//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

#define ESTSettingBaseErrorDomain @"ESTSettingBaseErrorDomain"

@class ESTSettingBase, ESTDeviceConnectable;

typedef NS_ENUM(NSInteger, ESTSettingBaseError)
{
    ESTSettingBaseErrorDeviceReferenceNotAvailable
};

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block used as a result of operation.
 *
 *  @param setting Current setting.
 *  @param error Error of operation. No error means success.
 */
typedef void(^ESTSettingCompletionBlock)(ESTSettingBase * _Nullable setting, NSError * _Nullable  error);


/**
 *  ESTSettingBase defines a base class for all device related settings.
 */
@interface ESTSettingBase : NSObject

/**
 *  Method allows to initialize setting with data.
 *
 *  @param data Data describing desired value of setting.
 *
 *  @return Initialized object.
 */
- (instancetype)initWithData:(NSData *)data;

/**
 *  Method allows to verify if provided setting is not a duplicate 
 *  of another one. Estimote SDK expects to have one setting 
 *  of each kind for single device. It means that settings 
 *  of the same class should not be duplicated in Setting Manager.
 *  there are some exceptions though (like Generic Advertisers)
 *  where next to the class another parameter is important
 *  (Advertiser ID for example above). In that situation method should
 *  be overridden in particular class.
 *
 *  @param setting Satting the comparison should be made to.
 *
 *  @return Result of duplicate validation.
 */
- (BOOL)isDuplicateOfSetting:(ESTSettingBase *)setting;

@end


@interface ESTSettingBase (Internal)

/**
 *  The device that setting should be read from / written to.
 *  Required for -readValueWithCompletion: and -writeValue:completion: methods to work.
 *
 *  @see -[ESTSettingReadOnly readValueWithCompletion:], -[ESTSettingReadWrite writeValue:completion:].
 */
@property (nonatomic, weak) ESTDeviceConnectable *device;

@end

NS_ASSUME_NONNULL_END
