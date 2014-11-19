//
//  ESConcurrentOperation.h
//  EstimoteSDK
//
//  Version: 2.2.0
//  Created by Marcin Klimek on 16/10/14.
//  Copyright (c) 2014 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

/**
 *  Base class for concurrent |NSOperation|. It this based from examples from Apple's Concurrency Programming Guide. A subclass should override -(void)main method to start performing task and call completeOperation when it is done. Because this is a concurrent operation, your start: method can finish and you can wait for any delegates to finish. When all execution is finished, you need to call completeOperation. If not, your operation will be treated as not finished.
 */
@interface ESConcurrentOperation : NSOperation

/**
 *  Override this method to start execution of your task.
 */
- (void)main;

/**
 *  Call this method when your task is finished with all work.
 */
- (void)completeOperation;

@end
