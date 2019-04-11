Pod::Spec.new do |spec|
  spec.name = "EstimoteFleetManagementSDK"
  spec.version = "4.29.0"
  spec.summary = "iOS library for managing Estimote Beacons."
  spec.homepage = "https://github.com/Estimote/iOS-FleetManagement-SDK"
  spec.license = { type: "Apache 2.0", file: "LICENSE" }
  spec.authors = { "Estimote, Inc" => "contact@estimote.com" }
  spec.source = { git: "git@github.com:Estimote/iOS-FleetManagement-SDK.git", tag: spec.version }
  spec.social_media_url = "https://twitter.com/estimote"
  spec.platform = :ios
  spec.vendored_frameworks = "EstimoteFleetManagementSDK/EstimoteFleetManagementSDK.framework"
  spec.ios.deployment_target = "10.0"
end

