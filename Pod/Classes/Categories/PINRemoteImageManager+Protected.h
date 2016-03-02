//
//  PINRemoteImageManager+Protected.h
//  PINRemoteImage
//
//  Created by Aleksey Kiselev on 02/03/16.
//  Copyright © 2016 Pinterest. All rights reserved.
//

#import <PINRemoteImage/PINRemoteImage.h>
@class PINDataTaskOperation;
/**
This category typically should only be used by subclasses of PINRemoteImageManager, which can implement own download process.
 */
@interface PINRemoteImageManager (Protected)

/**
 Concurrent URL Session Task Queue for data task operations
 */
@property (nonatomic, strong, readonly) NSOperationQueue *urlSessionTaskQueue;

/**
 Exposing type for protected method
 */
typedef void (^PINRemoteImageManagerDataCompletion)(NSData *data, NSError *error);
/**
 The method which creates operation with data downloading procedure
 
 @param url NSURL where the data to download resides.
 @param key cache key.
 @param priority sets the queue priority for data task operation
 @param completion PINRemoteImageManagerDataCompletion block to call when when downloaded.
 @return PINDataTaskOperation - subclass of NSOperation, that can start download process
 */
- (PINDataTaskOperation *)downloadDataWithURL:(NSURL *)url
                                          key:(NSString *)key
                                     priority:(PINRemoteImageManagerPriority)priority
                                   completion:(PINRemoteImageManagerDataCompletion)completion;
@end
