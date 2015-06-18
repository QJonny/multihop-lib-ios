//
//  MH6ShotsProtocol.h
//  Multihop
//
//  Created by quarta on 04/04/15.
//  Copyright (c) 2015 quarta. All rights reserved.
//

#ifndef Multihop_MH6ShotsProtocol_h
#define Multihop_MH6ShotsProtocol_h

#import "MHRoutingProtocol.h"
#import "MHLocationManager.h"
#import "MH6ShotsScheduler.h"
#import "MHConfig.h"



#define MH6SHOTS_JOIN_MSG @"-[join-msg]-"
#define MH6SHOTS_LEAVE_MSG @"-[leave-msg]-"

@interface MH6ShotsProtocol : MHRoutingProtocol


#pragma mark - Initialization
- (instancetype)initWithServiceType:(NSString *)serviceType
                        displayName:(NSString *)displayName;


- (void)disconnect;

- (void)joinGroup:(NSString *)groupName;

- (void)leaveGroup:(NSString *)groupName;

- (void)sendPacket:(MHPacket *)packet
             error:(NSError **)error;


@end


#endif
