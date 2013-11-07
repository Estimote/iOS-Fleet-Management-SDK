Pod::Spec.new do |s|
  s.name         = "EstimoteSDK"
  s.version      = "1.0.0"
  s.summary      = "iOS library for Estimote iBeacon devices"
  s.homepage     = "http://estimote.com"
  s.author       = { "Estimote, Inc" => "contact@estimote.com" }
  s.platform     = :ios 
  s.source       = { :git => "https://github.com/Estimote/iOS-SDK.git", :tag => "v#{s.version}" }
  s.source_files  = 'EstimoteSDK/**/*.{m,h}'
  s.private_header_files =  'EstimoteSDK/Headers/*.h'
  s.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration', 'MobileCoreServices', 'CoreLocation'
  s.requires_arc = true
end