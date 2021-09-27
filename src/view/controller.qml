import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 2.15
import QtQml 2.15
import Qt.labs.platform 1.1

Window {
	property var windowModel
	property var dataModel

	id: window
	visible: true
	width: 800
	height: 800

	Column {
		Text {
			text: "Window controls"
			width: window.width
			horizontalAlignment: Text.AlignHCenter
			font.pointSize: 24
		}

		Row {
			width: window.width
			
			Text {
				id: height_label
				text: "Height"
				width: 100
			}

			Slider {
				id: height_slider
				from: 50
				value: windowModel.windowHeight
				to: 400
				snapMode: Slider.SnapAlways
				stepSize: 1
				width: window.width - height_text.width - height_label.width
			}

			Text {
				id: height_text
				text: height_slider.value
				width: 40
				horizontalAlignment: Text.AlignRight
			}
		}

		Row {
			width: window.width
			
			Text {
				id: width_label
				text: "Width"
				width: 100
			}

			Slider {
				id: width_slider
				from: 200
				value: windowModel.windowWidth
				to: 1000
				snapMode: Slider.SnapAlways
				stepSize: 1
				width: window.width - width_text.width - width_label.width
			}

			Text {
				id: width_text
				text: width_slider.value
				width: 40
				horizontalAlignment: Text.AlignRight
			}
		}

		Row {
			width: window.width
			
			Text {
				id: gap_label
				text: "Gap"
				width: 100
			}

			Slider {
				id: gap_slider
				from: 0
				value: windowModel.gap
				to: 200
				snapMode: Slider.SnapAlways
				stepSize: 1
				width: window.width - gap_text.width - gap_label.width
			}

			Text {
				id: gap_text
				text: gap_slider.value
				width: 40
				horizontalAlignment: Text.AlignRight
			}
		}

		Row {
			width: window.width
			
			Text {
				id: margin_label
				text: "Margin"
				width: 100
			}

			Slider {
				id: margin_slider
				from: 0
				value: windowModel.margin
				to: 50
				snapMode: Slider.SnapAlways
				stepSize: 1
				width: window.width - margin_text.width - margin_label.width
			}

			Text {
				id: margin_text
				text: margin_slider.value
				width: 40
				horizontalAlignment: Text.AlignRight
			}
		}

		Row {
			Text {
				id: backgroundPath
				text: windowModel.path
				width: window.width - backgroundButton.width
			}

			Button {
				id: backgroundButton
				text: "Load background"
				onClicked: {
					backgroundDialog.open()
				}
				width: 200
			}
			
			FileDialog {
				id: backgroundDialog
				title: "Please choose a file"
				fileMode: FileDialog.OpenFile
				nameFilters: ["All files (*)"]
				onAccepted: {
					windowModel.path = backgroundDialog.file;
				}
			}
		}		

		ToolSeparator {
			orientation: Qt.Horizontal
			width: window.width
		}

		Text {
			text: "Players"
			width: window.width
			horizontalAlignment: Text.AlignHCenter
			font.pointSize: 24
		}

		Row {
			Text {
				id: filePath
				text: dataModel.path
				width: window.width - fileButton.width
			}

			Button {
				id: fileButton
				text: "Load file"
				onClicked: {
					fileDialog.open()
				}
				width: 200
			}
			
			FileDialog {
				id: fileDialog
				title: "Please choose a file"
				fileMode: FileDialog.OpenFile
				nameFilters: ["Json files (*.json)"]
				onAccepted: {
					dataModel.path = fileDialog.file;
				}
			}
		}

		Row {
			id: addRow

			Text {
				text: "Pro name"
				width: (window.width - addButton.width) / 4
			}

			Rectangle {
				color: "gray"
				width: (window.width - addButton.width) / 4
				height: addRow.height

				TextInput {
					id: proName
					text: ""
					width: (window.width - addButton.width) / 4
				}
			}

			Text {
				text: "Summoner name"
				width: (window.width - addButton.width) / 4
			}

			Rectangle {
				color: "gray"
				width: (window.width - addButton.width) / 4
				height: addRow.height

				TextInput {
					id: summonerName
					text: ""
					width: (window.width - addButton.width) / 4
				}
			}

			Button {
				id: addButton
				text: "Add player"
				onClicked: {
					dataModel.addPlayer(proName.text, summonerName.text);
					proName.text = "";
					summonerName.text = "";
				}
				width: 200
			}
		}

		ToolSeparator {
			orientation: Qt.Horizontal
			width: window.width
		}
	}

	Binding {
		target: window.windowModel
		property: "windowWidth"
		value: width_slider.value
	}

	Binding {
		target: window.windowModel
		property: "windowHeight"
		value: height_slider.value
	}

	Binding {
		target: window.windowModel
		property: "gap"
		value: gap_slider.value
	}
	
	Binding {
		target: window.windowModel
		property: "margin"
		value: margin_slider.value
	}

	onClosing: {
		Qt.quit();
	}
}
