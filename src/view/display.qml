import QtQuick 2.6
import QtQuick.Window 2.1

Window {
	property var windowModel
	property var currentPlayers

	id: window
	visible: true
	flags: Qt.MSWindowsFixedSizeDialogHint | Qt.WindowTransparentForInput
	width: windowModel.windowWidth
	minimumWidth: width
	maximumWidth: width
	height: windowModel.windowHeight
	minimumHeight: height
	maximumHeight: height
	color: "transparent"

	Image {
		fillMode: Image.Stretch
		source: windowModel.path
		width: window.width
		height: window.height
	}

	Row {
		width: window.width

		Text {
			text: currentPlayers.blueTeam.join("\n")
			font.family: "Helvetica"
			horizontalAlignment: Text.AlignRight
			verticalAlignment: Text.AlignVCenter
			fontSizeMode: Text.Fit
			minimumPixelSize: 10
			font.pixelSize: 72
			color: "blue"
			width: (window.width - windowModel.gap) / 2
			height: window.height
			padding: windowModel.margin
		}

		Rectangle {
			width: windowModel.gap
			height: window.height
			color: "transparent"
		}

		Text {
			text: currentPlayers.redTeam.join("\n")
			font.family: "Helvetica"
			horizontalAlignment: Text.AlignLeft
			verticalAlignment: Text.AlignVCenter
			fontSizeMode: Text.Fit
			minimumPixelSize: 10
			font.pixelSize: 72
			color: "red"
			width: (window.width - windowModel.gap) / 2
			height: window.height
			padding: windowModel.margin
		}
	}
}
