extension CLProximity {

    var description: String {
        switch self {
        case .Unknown: return "Unk"
        case .Immediate: return "Imm"
        case .Near: return "Near"
        case .Far: return "Far"
        }
    }

}
