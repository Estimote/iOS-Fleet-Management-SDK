extension CLProximity {

    var description: String {
        switch self {
        case .unknown: return "Unk"
        case .immediate: return "Imm"
        case .near: return "Near"
        case .far: return "Far"
        }
    }

}
