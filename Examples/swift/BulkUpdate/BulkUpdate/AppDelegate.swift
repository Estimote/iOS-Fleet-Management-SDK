//
//  AppDelegate.swift
//  BulkUpdate
//
//  Created by Dawid Rączka on 02/09/16.
//  Copyright © 2016 Dawid Rączka. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        
        // TODO: put your App ID and App Token here
        // You can get them by adding your app on https://cloud.estimote.com/#/apps
        
        //ESTConfig.setupAppID("<#App ID#>", andAppToken: "<#App Token#>")

        return true
    }
}

