
#import <Foundation/Foundation.h>
@protocol ESTDecryptedFrameVO;
@protocol ESTRequestConfiguration;
@class ESTURLSessionCompletionProcessor;
@class ESTCloudCredentials;

NS_ASSUME_NONNULL_BEGIN

/**
 Asks Estimote Cloud for original frame by sending the ecrypted payload data.
 The encrypted frames are broadcast by devices with Estimote Secure Monitoring enabled.
 */
@interface ESTDecryptedFrameGetter : NSObject

/**
 Unavailable. Use designated init.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Unavailable. Use designated init.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Convenience init. Calls designated init with default URL session, newly created ESTURLSessionCompletionProcessor
 and request configuration for Estimote Secure Monitoring service created with cloud credentials.

 @param cloudCredentials Credentials passed to request configuration object.
 */
- (instancetype)initWithCloudCredentials:(ESTCloudCredentials *)cloudCredentials;

/**
 Designated init.

 @param urlSession Object used to create data tasks.
 @param completionProcessor Object invoked with URL session completion params.
 @param requestConfiguration Object used to configure HTTP request.
 */
- (instancetype)initWithURLSession:(NSURLSession *)urlSession
     urlSessionCompletionProcessor:(ESTURLSessionCompletionProcessor *)completionProcessor
              requestConfiguration:(id<ESTRequestConfiguration>)requestConfiguration NS_DESIGNATED_INITIALIZER;

/**
 Construct URL request, send it and call completion block with deserialized response.

 @param encryptedFramePayloadData Encrypted frame payload data.
 @param completion Block to be called after request finishes. When request fails, the error objects is not-nil,
                   its domain is ESTURLSessionCompletionProcessorErrorDomain, and its code is a case of ESTURLSessionCompletionProcessorError.
 */
- (void)getDecryptedFrameWithEncryptedPayloadData:(NSData *)encryptedPayloadData
                                       completion:(void (^)(id<ESTDecryptedFrameVO> _Nullable result, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
