# Purpose

- The GRILLDISExample project is an demo project for the GRILL DIS for Unreal plugin, showing how to utilize features of the plugin.

# Get Started

- This example project utilizes Unreal Engine 4.27.
- Clone this repository
- Open GRILLDISExample\GRILLDISExample.uproject and allow it to build modules.

# Usage

![DIS Game Manager](/uploads/e5c5ebbc74a6af5bd8eff63efa326b3b/image.png)

- Once the project is open, verify that DIS Enumeration mappings exist.
    - Click on the DIS Game Manager in the 'DIS_DemoLevel' level and locate the DIS Enumeration Mapping UAsset that is currently set to the DIS Enumeration Mapping variable.
    	- Open up the UAsset and then expand the 'DIS Enumeration Mappings' dropdown.
    	- Add desired actor to DIS Enumeration mappings.
	        - _**NOTE:**_ The actors tied to DIS Enumerations have to implement the DIS Interface supplied by the GRILL DIS for Unreal plugin and also should have a DIS Component attached to them. Implement the DIS Interface functions to return the associated DIS component of the actor. Refer to the _**GRILL DIS for Unreal**_ plugin readme for more information.
	- _**NOTE:**_ If desired, a new DIS Enumeration Mapping UAsset can be created. To do so, right click in the Content Browser, hover Blueprints, and then select the DIS Enumeration Mapping UAsset option. Once created, populate the mappings, and then replace the Enumeration Mapping in the DISGameManager actor with the new created mapping. Refer to the _**GRILL DIS for Unreal**_ plugin readme for more information.

![DISEnumMappingUAsset](/uploads/e4aeae7696eee1dc13c730ad55ff2e66/image.png)

![DISEnumMappings](/uploads/664dbca6f0271ce5a97708c373de78af/image.png)

- After DIS Enumeration mappings are created, click on play.

![DISOptionsButton](/uploads/e9c5280b2fc445b55b177b7e1bf4b0ad/image.png)

![DISVisualOptions](/uploads/98cfc0b98b528f5a0b2034fc995ca355/image.png)

- Click on the 'DIS Options' button on the menu that appears on start.
    - Change the visuals as desired.
        - Entity Labels: An overhead icon for the DIS Entities showing their marking, distance from user, and altitude (if applicable).
            - Entity labels can be clicked on to show additional information on the entity.
        - Entity Icons: An icon that will appear to represent the entity when the user is a certain distance away.
            - Entity icons are currently all the same, but they could be updated to show MIL STD icons for example.
        - Entity Ribbon Trails: Trails that appear behind the DIS Entities to show the path that they have taken.
            - _**NOTE:**_ These visuals are buggy with Cesium if relocating the origin is enabled.

![DISNetworkingOptions](/uploads/105bf435acf35e7897dc5c6bfd54c5b5/image.png)

- Change the network settings as desired.
    - Exercise ID/Site ID/Application ID: DIS specific settings.
		- _**NOTE:**_ Exercise ID needs to match that of what is being sent on the network in order to handle the received packets.
    - Receive IP Address: Address to receive DIS packets on.
        - _**NOTE:**_ A receive IP address of 0.0.0.0 will listen to all DIS packets on the network.
    - Receive Port: The port to receive DIS packets on.
    - Send IP Address: The IP address to send DIS packets on.
    - Send IP Address: The port to send DIS packets on.
- Click on Connect to connect to the network (opens a UDP socket)



- Once all desired options are set, hit 'Apply & Close'. Then click on 'Start' if haven't already.
    - _**NOTE:**_ 'DIS Options' can be changed even after 'Start' is clicked via the 'Options' button that appears in the top right hand corner.

![InGameMenu](/uploads/8f105a47e73dbf9b683eb5162ee112d3/image.png)

- If DIS packets are being sent across the network and DIS mappings have been set, then DIS entities should start appearing in the world.
    - _**NOTE:**_ If custom DIS packets are desired to be sent by the sim, refer to the Modifying section below.
- Click on the 'Entities' button in the top right hand corner of the screen to see available DIS Entities in the world.
    - The DIS Entities labels in the listing can be selected to view at various camera angles.
    - Either double click on an entity to go to direct view or select an entity and change the camera dropdown on the bottom right.
        - _**NOTE:**_ Once the camera dropdown is changed away from 'Free Flying', just clicking on an entity will change the camera view to that entity.
        - The available camera options are:
            - Free Flying: Not attached to an entity. User controlled. See the below 'Movement' section for details on controlling it.
            - Direct View: A fixed direct view out the front of the entity. Moves and rotates with the entity.
            - Orbital View - Local: An orbital view of the entity. Moves and rotates with the entity, but can be further rotated around the entity in an orbital perspective. See the below 'Movement' section for details on controlling it.
            - Orbital View - World: An orbital view of the entity. Moves with the entity, but does not rotate with it. It be rotated around the entity in an orbital perspective. See the below 'Movement' section for details on controlling it.

![DISEntityViewer](/uploads/4a6f84d19c9be55ef79da082f8d74ada/image.png)

![DISEntityCameraOptions](/uploads/2a9da500404e913183d1641a8adb2ac9/DISEntityCameraOptions.png)

# Movement

- Free Flying Camera movement:
    - Click & Hold & Drag inside the Viewport to look around.
    - W, A, S, D to move.
    - Scrollwheel to increase/decrease speed.
- Orbital View Camera movement:
    - Click & Hold & Drag inside the Viewport to look around.

# Modifying

![DISEntities](/uploads/b7c1800fc027ceada6bdc11e882b1245/image.png)

- Handling of DIS packets is performed by the each individual DIS Entity.
    - Open up the 'DISEntity_BPBase' actor located in the '\Game\Actors\DISEntities' folder to view how receiving is being performed.
	- Open up the 'DISEntity_ExampleSending' actor located in the '\Game\Actors\DISEntities' folder to view how sending is being performed.
    - Additional DIS packet processing is performed by the GRILL DIS for Unreal plugin. Refer to its README for additional details.
- Handling of UDP connections is performed in the 'DISGameState' located in the '\Game\GameModeBPs' folder.

![DISGameState](/uploads/a0e2b745e9a0f95a42389310ef97d029/image.png)

# Troubleshooting

- If no DIS entities are appearing in the game, try the below steps:
    - Look at the 'World Outliner' and check if the DIS Entities show there.
        - If so, try enabling DIS labels if not enabled already to locate them in the world.
    - Look at the 'Output Log' and see if there are warning messages being printed out from the DISGameManager stating that 'No mapping exists between an actor and the DIS Enumeration of: ...'
        - If so, double check the DIS Enumeration mappings that were setup ealier and verify they were setup appropriately.
    - Verify DIS packets are being sent on the network. This can be done via Wireshark.
