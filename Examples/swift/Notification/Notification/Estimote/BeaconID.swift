//
// Please report any problems with this app template to contact@estimote.com
//

struct BeaconID: Equatable, CustomStringConvertible, Hashable {

    let proximityUUID: NSUUID
    let major: CLBeaconMajorValue
    let minor: CLBeaconMinorValue

    init(proximityUUID: NSUUID, major: CLBeaconMajorValue, minor: CLBeaconMinorValue) {
        self.proximityUUID = proximityUUID
        self.major = major
        self.minor = minor
    }

    init(UUIDString: String, major: CLBeaconMajorValue, minor: CLBeaconMinorValue) {
        self.init(proximityUUID: NSUUID(UUIDString: UUIDString)!, major: major, minor: minor)
    }

    var asString: String {
        get { return "\(proximityUUID.UUIDString):\(major):\(minor)" }
    }

    var asBeaconRegion: CLBeaconRegion {
        get { return CLBeaconRegion(
            proximityUUID: self.proximityUUID, major: self.major, minor: self.minor,
            identifier: self.asString) }
    }

    var description: String {
        get { return self.asString }
    }

    var hashValue: Int {
        get { return self.asString.hashValue }
    }

}

func ==(lhs: BeaconID, rhs: BeaconID) -> Bool {
    return lhs.proximityUUID == rhs.proximityUUID
        && lhs.major == rhs.major
        && lhs.minor == rhs.minor
}

extension CLBeacon {

    var beaconID: BeaconID {
        get { return BeaconID(
            proximityUUID: proximityUUID,
            major: major.unsignedShortValue,
            minor: minor.unsignedShortValue) }
    }

}
