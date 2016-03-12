//
// Please report any problems with this app template to contact@estimote.com
//

import UIKit

/**
 This is a utility view that renders a dashed, grayish border around it, as a hint where to place the beacon to initiate the setup process.
 */
@IBDesignable
class BeaconPlaceholderView: UILabel {

    var border: CAShapeLayer!

    override init(frame: CGRect) {
        super.init(frame: frame)
        initialize()
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        initialize()
    }

    func initialize() {
        border = CAShapeLayer()
        border.strokeColor = UIColor(white: 0.5, alpha: 1.0).CGColor
        border.fillColor = nil
        border.lineWidth = 5
        border.lineDashPattern = [10, 10]

        layer.addSublayer(border)
    }

    override func layoutSubviews() {
        super.layoutSubviews()

        border.path = UIBezierPath(rect: bounds).CGPath
        border.frame = bounds;
    }

}
