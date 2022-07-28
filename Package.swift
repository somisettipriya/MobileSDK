// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

// swift-tools-version:5.3
 
import PackageDescription

let package = Package(
    name: "MobileSDK",
    platforms: [
        .iOS(.v9),
        .macOS(.v10_10)
    ],
    products: [
        .library(
            name: "MobileSDK",
            targets: ["MobileSDK"]),
    ],
    targets: [
        .binaryTarget(
            name: "MobileSDK",
            path: "Frameworks/MobileSDK.xcframework"
        )
    ]
)
