class MajorMonitor: NSObject, ESTBeaconManagerDelegate {

    private let beaconManager = ESTBeaconManager()

    private var monitoredMajors = Set<CLBeaconMajorValue>()
    private var insideMajors = Set<CLBeaconMajorValue>()

    override init() {
        super.init()

        beaconManager.delegate = self
        beaconManager.requestAlwaysAuthorization()

        for region in beaconManager.monitoredRegions {
            beaconManager.stopMonitoringForRegion(region as! CLBeaconRegion)
        }
    }

    func ensureMonitoringForMajor(major: CLBeaconMajorValue) {
        if (monitoredMajors.contains(major)) { return }

        monitoredMajors.insert(major)
        beaconManager.startMonitoringForRegion(beaconRegionForMajor(major))
    }

    func isInsideMajor(major: CLBeaconMajorValue) -> Bool {
        return insideMajors.contains(major)
    }

    // MARK: Beacon Manager delegate

    func beaconManager(manager: AnyObject, didDetermineState state: CLRegionState, forRegion region: CLBeaconRegion) {
        guard let major = region.major?.unsignedShortValue else { return }

        if state == .Inside {
            insideMajors.insert(major)
        } else if state == .Outside {
            insideMajors.remove(major)
        }
    }

    func beaconManager(manager: AnyObject, didEnterRegion region: CLBeaconRegion) {
        guard let major = region.major?.unsignedShortValue else { return }

        insideMajors.insert(major)
    }

    func beaconManager(manager: AnyObject, didExitRegion region: CLBeaconRegion) {
        guard let major = region.major?.unsignedShortValue else { return }

        insideMajors.remove(major)

        beaconManager.stopMonitoringForRegion(beaconRegionForMajor(major))
        monitoredMajors.remove(major)
    }

    // MARK: Helper methods

    private func beaconRegionForMajor(major: CLBeaconMajorValue) -> CLBeaconRegion {
        return CLBeaconRegion(proximityUUID: NSUUID(UUIDString: yourUUID)!, major: major, identifier: "\(major)")
    }

}
