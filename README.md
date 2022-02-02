# IronDev2021

IronDev is an event held at annually at the I/ITSEC conference in Orlando, Florida.  The competition begins in early November.  Teams are challenged to develop a solution up through the final date of the I/ITSEC conference.  The "secret ingredient" will be unveiled during the week of the conference.  Teams will have that final week to refine their solutions and integrate the secret ingredient.  Additional information can be found in the GRILL share: project\IronDev2021

# Getting started

Since the setting is stored locally, it is recommended to disable XRSimulation before running the default level.

1. Project Settings
1. Plugins section -> XR Simulation
1. Uncheck Enable Simulation

Doing the above will get rid of the hands that appears when running playing the default level

# Testing and using HoloLens 2

1. Project Settings
1. Plugins section -> XR Simulation
1. Ensure 'Enable Simulation' is checked

Open the TableTopLevel.

Install the remote renderer application on the HoloLens:
1. Run the remote renderer application on the HoloLens and note the IP address
1. Project Settings -> Windows Mixed Reality -> Enable Remoting For Editor (checked)
1. Fill in HoloLens IP address
1. Increase Max network transfer rate to 15000
1. Ensure Enable Input Simulation is checked (if you want to emulate HoloLens input)
1. Click Connect
1. Click Play in the Editor with VR Preview

# Concept

The GRILL's concepts for IronDev 2021 involves the following main tasks:

1. Integrate OpenDIS into Unreal Engine 4
2. Implement a few basic PDU types
3. Use Cesium for whole earth viewing capability
4. Use Cesium Ion or similar to have a shared AR/VR experience
5. Govern some basic 3D model positions from the EntityStatePDUs
6. Use LNCS or similar for DIS exercise playback

# OpenDIS integration

- Integrate OpenDIS into Unreal Engine 4.  Implement a few basic PDU types.
- Create data strutures and notification/messaging system for DIS data

# Cesium

- Use Cesium for whole-earth viewing capability
- Translate DIS positional data such that it be use to goven model positions in Cesium/UE4
- Use Cesium Ion or similar to provide VR/AR viewing

# 3D model integration

- Recommend using a fairly simple LNCS recording.  Strategically pick a subset of 3D models and their respective DIS enumerations.
- Develop a system and centralized data structure from which DIS enumerations can be easily mapped to 3D models.
- Consider using icons for representations when the distance is great.

# LNCS

- Consider using LNCS for DIS playback and additional viewing/troubleshooting capability

# AR/VR

- Ideally, we would demonstrate a shared, distributed experience using an AR headset as well as a VR headset.

# Features

- Basic UI to start software
- Camera manipulation: attach to DIS entities, free fly, orbit, chase
- Display of DIS info (pertinent metadata, marking, distance, etc.)
