//
//  MHPeer.h
//  Multihop
//
//  Created by quarta on 16/03/15.
//  Copyright (c) 2015 quarta. All rights reserved.
//

#ifndef Multihop_MHPeer_h
#define Multihop_MHPeer_h

#import <Foundation/Foundation.h>
#import <MultipeerConnectivity/MultipeerConnectivity.h>

#import "MHDatagram.h"
#import "MHPeerBuffer.h"

#import "MHConfig.h"


#define MHPEER_HEARTBEAT_MSG  @"[{_-heartbeat_msg-_}]"
#define MHPEER_CONGESTION_CONTROL_MSG  @"[{_-congestion_control_msg-_}]"

#define MHPEER_STARTHEARTBEAT_TIME 10

#define MHPEER_RECEIVING_DELAY_PRECISION 100


@protocol MHPeerDelegate;


@interface MHPeer : NSObject

#pragma mark - Properties

/// Delegate for the PartyTime methods
@property (nonatomic, weak) id<MHPeerDelegate> delegate;


/// Returns the current client's MCPeerID (this ID is different for each
/// application startup)
@property (nonatomic, readonly, strong) MCPeerID *mcPeerID;

/// Returns the current client's MHPeerID (this ID is defined by the Multihop
/// library and remains consistent between different application startups)
@property (nonatomic, readonly, strong) NSString *mhPeerID;

/// Returns the display name which was passed in when the object was initialized.
/// If no display name was specified, it defaults to [UIDevice currentDevice].name]
@property (nonatomic, readonly, strong) NSString *displayName;

@property (nonatomic, readonly, strong) MCSession *session;

#pragma mark - Initialization


- (instancetype)initWithDisplayName:(NSString *)displayName
     withOwnMCPeerID:(MCPeerID *)ownMCPeerID
     withOwnMHPeerID:(NSString *)ownMHPeerID
        withMCPeerID:(MCPeerID *)mcPeerID
        withMHPeerID:(NSString *)mhPeerID;

- (void)sendDatagram:(MHDatagram *)datagram
               error:(NSError **)error;

- (void)disconnect;

+ (MHPeer *)getOwnMHPeerWithDisplayName:(NSString *)displayName;

@end



/**
 The delegate for the MHPeer class.
 */
@protocol MHPeerDelegate <NSObject>

@required
- (void)mhPeer:(MHPeer *)mhPeer
hasDisconnected:(NSString *)info;

- (void)mhPeer:(MHPeer *)mhPeer
hasConnected:(NSString *)info;

- (void)mhPeer:(MHPeer *)mhPeer
didReceiveDatagram:(MHDatagram *)datagram;

@end

#endif
