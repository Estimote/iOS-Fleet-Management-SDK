//
//  DetailViewController.swift
//  AccelerometerExample-Swift
//
//  Created by Grzegorz Krukiewicz-Gacek on 05.01.2015.
//  Copyright (c) 2015 Estimote Inc. All rights reserved.
//

import UIKit

class DetailViewController: UIViewController, ESTNearableManagerDelegate {
    
    @IBOutlet weak var typeLabel: UILabel!
    @IBOutlet weak var orientationLabel: UILabel!
    @IBOutlet weak var accelerometerLabel: UILabel!
    
    var nearable:ESTNearable!
    var nearableManager:ESTNearableManager!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        nearableManager = ESTNearableManager()
        nearableManager.delegate = self
        nearableManager .startRangingForIdentifier(nearable.identifier)
        
        typeLabel.text = ESTNearableDefinitions.nameForType(nearable.type)
    }
    
    //MARK: - ESTNearableManager delegate
    
    func nearableManager(manager: ESTNearableManager!, didRangeNearable nearable: ESTNearable!) {
//        temperatureLabel.text = NSString(format: "%.1f°C", nearable.temperature)
        
        var orientationString:String
        if nearable.isMoving == false
        {
            switch nearable.orientation
            {
            case ESTNearableOrientation.Horizontal:
                orientationString = "Sticker is on its back"
            case ESTNearableOrientation.HorizontalUpsideDown:
                orientationString = "Sticker is on its front"
            case ESTNearableOrientation.Vertical:
                orientationString = "Sticker is on its legs"
            case ESTNearableOrientation.VerticalUpsideDown:
                orientationString = "Sticker is on its head"
            case ESTNearableOrientation.LeftSide:
                orientationString = "Sticker is on its left side"
            case ESTNearableOrientation.RightSide:
                orientationString = "Sticker is on its right side"
            case ESTNearableOrientation.Unknown:
                orientationString = "Sticker orientation unknown"
            }
        }
        else
        {
            orientationString = "Sticker is moving"
        }
        
        orientationLabel.text = orientationString
        
        self.accelerometerLabel.text = NSString(format: "x axis: %dmG \n y axis: %dmG \n z axis: %dmG \n",
        nearable.xAcceleration,
        nearable.yAcceleration,
        nearable.zAcceleration)
    }
}

