//
//  DetailViewController.swift
//  TemperatureExample-Swift
//
//  Created by Grzegorz Krukiewicz-Gacek on 24.12.2014.
//  Copyright (c) 2014 Estimote Inc. All rights reserved.
//

import UIKit

class DetailViewController: UIViewController, ESTNearableManagerDelegate {

    @IBOutlet weak var typeLabel: UILabel!
    @IBOutlet weak var temperatureLabel: UILabel!

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
        temperatureLabel.text = NSString(format: "%.1f°C", nearable.temperature)
    }
}

