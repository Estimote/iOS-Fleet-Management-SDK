Pod::Spec.new do |s|
  s.name         = "EstimoteSDK"
  s.version      = "5.0.0-alpha.1"
  s.summary      = "iOS library for Estimote devices"
  s.homepage     = "https://estimote.com"
  s.author       = { "Estimote, Inc" => "contact@estimote.com" }
  s.platform     = :ios
  s.source       = { :git => "https://github.com/Estimote/iOS-SDK.git", :tag => "5.0.0-alpha.1" }
  s.source_files =  'EstimoteSDKv5/EstimoteSDKv5.framework/Versions/A/Headers/*.h'
  s.vendored_frameworks = 'EstimoteSDKv5/EstimoteSDKv5.framework'
  s.ios.deployment_target = '8.0'
  s.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration', 'MobileCoreServices', 'CoreLocation', 'CoreBluetooth'
  s.requires_arc = true
  s.xcconfig  =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/EstimoteSDKv5"',
                   'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/Headers/EstimoteSDKv5"' }
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2017 Estimote, Inc. All rights reserved.
      LICENSE
  }
end
