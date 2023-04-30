#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
//	addAndMakeVisible(ipAddressLabel_);
//	ipAddressLabel_.setEditable(false, false, false);
//	ipAddressLabel_.setText("IP LAN Address", juce::dontSendNotification);
	// set the font size to 40 and make it bold
	ipAddressLabel_.setFont(juce::Font(40.0f, juce::Font::bold));
    ipAddressLabel2_.setEditable(false, false, false);
	// set the font size to 40 and make it bold
	ipAddressLabel2_.setFont(juce::Font(40.0f, juce::Font::bold));
    addAndMakeVisible(ipAddressLabel2_);
	
	
	addAndMakeVisible(quitButton);
	quitButton.setButtonText("Exit");

	quitButton.addListener(this);
	// add a GroupComponent around the labels and button
	addAndMakeVisible(groupComponent);
	// set the text for the group component to say "IP Address"
	groupComponent.setText("Lan IP Address");
	// set the color of the group component to white
	groupComponent.setColour(juce::GroupComponent::outlineColourId, juce::Colours::blue);




	juce::Array<juce::IPAddress> ipAddresses;
	ipAddresses = juce::IPAddress::getAllAddresses(false);
	juce::String filteredIp;

	for (int i = 0; i < ipAddresses.size(); ++i)
	{
		auto ipAddress = ipAddresses[i].toString();

		if (ipAddress.startsWith("192"))
		{
			filteredIp = ipAddress;
			break;
		}
	}

	if (filteredIp.isEmpty())
	{
		ipAddressLabel2_.setText("No IP addresses found", juce::dontSendNotification);
	}
	else
	{
		ipAddressLabel2_.setText("IP:   " + filteredIp, juce::dontSendNotification);
	}

    setSize (475, 200);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
   // g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
  //  ipAddressLabel_.setBounds((getWidth() / 4) - 25, 10, 400, 30);
    ipAddressLabel2_.setBounds((getWidth() / 6) - 25, 60, 400,30);
    quitButton.setBounds((getWidth() / 3) - 15, 125, 150, 40);
	// set the bounds of the group component to be the same as the bounds of the main component with a 10 pixel margin
	groupComponent.setBounds(getLocalBounds().reduced(10));
}

void MainComponent::buttonClicked(juce::Button* button)
{
	if (button == &quitButton)
	{
		juce::JUCEApplicationBase::quit();
	}
}