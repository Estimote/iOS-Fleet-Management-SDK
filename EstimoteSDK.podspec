Pod::Spec.new do |s|
  s.name         = "EstimoteSDK"
  s.version      = "3.2.5"
  s.summary      = "iOS library for Estimote iBeacon devices"
  s.homepage     = "http://estimote.com"
  s.author       = { "Estimote, Inc" => "contact@estimote.com" }
  s.platform     = :ios 
  s.source       = { :git => "https://github.com/Estimote/iOS-SDK.git", :tag => "3.2.5" }
  s.source_files =  'EstimoteSDK/EstimoteSDK.framework/Versions/A/Headers/*.h'
  s.vendored_frameworks = 'EstimoteSDK/EstimoteSDK.framework'
  s.ios.deployment_target = '7.0'
  s.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration', 'MobileCoreServices', 'CoreLocation', 'CoreBluetooth'
  s.requires_arc = true
  s.xcconfig  =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/EstimoteSDK"',
                   'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/Headers/EstimoteSDK"' }
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2014 Estimote, Inc. All rights reserved.
      LICENSE
  }
end
