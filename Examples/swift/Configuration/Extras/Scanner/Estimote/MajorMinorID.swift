struct MajorMinorID: Equatable, Hashable, CustomStringConvertible {

    let major: CLBeaconMajorValue
    let minor: CLBeaconMinorValue

    private let majorMinorString: String

    init(major: CLBeaconMajorValue, minor: CLBeaconMinorValue) {
        self.major = major
        self.minor = minor

        majorMinorString = "\(major):\(minor)"
    }

    var description: String {
        get { return majorMinorString }
    }

    var hashValue: Int {
        get { return majorMinorString.hashValue }
    }

}

func ==(lhs: MajorMinorID, rhs: MajorMinorID) -> Bool {
    return lhs.major == rhs.major && lhs.minor == rhs.minor
}
