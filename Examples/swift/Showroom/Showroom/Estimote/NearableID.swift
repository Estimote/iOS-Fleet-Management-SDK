//
// Please report any problems with this app template to contact@estimote.com
//

struct NearableID: Equatable, CustomStringConvertible, Hashable {

    let nearableIDString: String

    init?(nearableIDString: String) {
        self.nearableIDString = nearableIDString
    }

    var description: String {
        get { return self.nearableIDString }
    }

    var hashValue: Int {
        get { return self.nearableIDString.hashValue }
    }

}

func ==(lhs: NearableID, rhs: NearableID) -> Bool {
    return lhs.nearableIDString == rhs.nearableIDString
}
