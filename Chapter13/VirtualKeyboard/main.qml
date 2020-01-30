import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.VirtualKeyboard 2.4
import QtQuick.Controls 2.12

Window {
	id: window
	visible: true
	width: 640
	height: 480
	title: qsTr("Hello World")

	TextField {
		id: textInput
		x: 100
		y: 100
		placeholderText: qsTr("Enter text here")
	}

	InputPanel {
		id: inputPanel
		z: 99
		x: 0
		y: window.height
		width: window.width

		states: State {
			name: "visible"
			when: inputPanel.active
			PropertyChanges {
				target: inputPanel
				y: window.height - inputPanel.height
			}
		}
		transitions: Transition {
			from: ""
			to: "visible"
			reversible: true
			ParallelAnimation {
				NumberAnimation {
					properties: "y"
					duration: 250
					easing.type: Easing.InOutQuad
				}
			}
		}
	}
}
