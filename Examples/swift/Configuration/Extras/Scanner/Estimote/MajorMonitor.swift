class MajorMonitor: NSObject, ESTBeaconManagerDelegate {

    fileprivate let beaconManager = ESTBeaconManager()

    fileprivate var monitoredMajors = Set<CLBeaconMajorValue>()
    fileprivate var insideMajors = Set<CLBeaconMajorValue>()

    override init() {
        super.init()

        beaconManager.delegate = self
        beaconManager.requestAlwaysAuthorization()

        for region in beaconManager.monitoredRegions {
            beaconManager.stopMonitoring(for: region as! CLBeaconRegion)
        }
    }

    func ensureMonitoringForMajor(_ major: CLBeaconMajorValue) {
        if (monitoredMajors.contains(major)) { return }

        monitoredMajors.insert(major)
        beaconManager.startMonitoring(for: beaconRegionForMajor(major))
    }

    func isInsideMajor(_ major: CLBeaconMajorValue) -> Bool {
        return insideMajors.contains(major)
    }

    // MARK: Beacon Manager delegate

    func beaconManager(_ manager: Any, didDetermineState state: CLRegionState, for region: CLBeaconRegion) {
        guard let major = region.major?.uint16Value else { return }
        
        if state == .inside {
            insideMajors.insert(major)
        } else if state == .outside {
            insideMajors.remove(major)
        }
    }
    
    func beaconManager(_ manager: Any, didEnter region: CLBeaconRegion) {
        guard let major = region.major?.uint16Value else { return }
        
        insideMajors.insert(major)
    }

    func beaconManager(_ manager: Any, didExitRegion region: CLBeaconRegion) {
        guard let major = region.major?.uint16Value else { return }
        
        insideMajors.remove(major)
        
        beaconManager.stopMonitoring(for: beaconRegionForMajor(major))
        monitoredMajors.remove(major)
    }

    // MARK: Helper methods

    fileprivate func beaconRegionForMajor(_ major: CLBeaconMajorValue) -> CLBeaconRegion {
        return CLBeaconRegion(proximityUUID: NSUUID(uuidString: yourUUID)! as UUID, major: major, identifier: "\(major)")
    }

}
