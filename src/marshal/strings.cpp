//==========================================================================
// Name        : strings.cpp
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "strings.h"

namespace evetools {

namespace marshal {

bool strings::m_init = false;
std::map<unsigned int, std::string> strings::m_strings;

strings::strings() {

}

strings::~strings() {

}

void strings::init() {

	if (strings::m_init) {
		return;
	}

	insert(0, "None");
	insert(1, "*corpid");
	insert(2, "*locationid");
	insert(3, "age");
	insert(4, "Asteroid");
	insert(5, "authentication");
	insert(6, "ballID");
	insert(7, "beyonce");
	insert(8, "bloodlineID");
	insert(9, "capacity");
	insert(10, "categoryID");
	insert(11, "character");
	insert(12, "characterID");
	insert(13, "characterName");
	insert(14, "characterType");
	insert(15, "charID");
	insert(16, "chatx");
	insert(17, "clientID");
	insert(18, "config");
	insert(19, "contraband");
	insert(20, "corporationDateTime");
	insert(21, "corporationID");
	insert(22, "createDateTime");
	insert(23, "customInfo");
	insert(24, "description");
	insert(25, "divisionID");
	insert(26, "DoDestinyUpdate");
	insert(27, "dogmaIM");
	insert(28, "EVE System");
	insert(29, "flag");
	insert(30, "foo.SlimItem");
	insert(31, "gangID");
	insert(32, "Gemini");
	insert(33, "gender");
	insert(34, "graphicID");
	insert(35, "groupID");
	insert(36, "header");
	insert(37, "idName");
	insert(38, "invbroker");
	insert(39, "itemID");
	insert(40, "items");
	insert(41, "jumps");
	insert(42, "line");
	insert(43, "lines");
	insert(44, "locationID");
	insert(45, "locationName");
	insert(46, "macho.CallReq");
	insert(47, "macho.CallRsp");
	insert(48, "macho.MachoAddress");
	insert(49, "macho.Notification");
	insert(50, "macho.SessionChangeNotification");
	insert(51, "modules");
	insert(52, "name");
	insert(53, "objectCaching");
	insert(54, "objectCaching.CachedObject");
	insert(55, "OnChatJoin");
	insert(56, "OnChatLeave");
	insert(57, "OnChatSpeak");
	insert(58, "OnGodmaShipEffect");
	insert(59, "OnItemChange");
	insert(60, "OnModuleAttributeChange");
	insert(61, "OnMultiEvent");
	insert(62, "orbitID");
	insert(63, "ownerID");
	insert(64, "ownerName");
	insert(65, "quantity");
	insert(66, "raceID");
	insert(67, "RowClass");
	insert(68, "securityStatus");
	insert(69, "Sentry Gun");
	insert(70, "sessionchange");
	insert(71, "singleton");
	insert(72, "skillEffect");
	insert(73, "squadronID");
	insert(74, "typeID");
	insert(75, "used");
	insert(76, "userID");
	insert(77, "util.CachedObject");
	insert(78, "util.IndexRowset");
	insert(79, "util.Moniker");
	insert(80, "util.Row");
	insert(81, "util.Rowset");
	insert(82, "*multicastID");
	insert(83, "AddBalls");
	insert(84, "AttackHit3");
	insert(85, "AttackHit3R");
	insert(86, "AttackHit4R");
	insert(87, "DoDestinyUpdates");
	insert(88, "GetLocationsEx");
	insert(89, "InvalidateCachedObjects");
	insert(90, "JoinChannel");
	insert(91, "LSC");
	insert(92, "LaunchMissile");
	insert(93, "LeaveChannel");
	insert(94, "OID+");
	insert(95, "OID-");
	insert(96, "OnAggressionChange");
	insert(97, "OnCharGangChange");
	insert(98, "OnCharNoLongerInStation");
	insert(99, "OnCharNowInStation");
	insert(100, "OnDamageMessage");
	insert(101, "OnDamageStateChange");
	insert(102, "OnEffectHit");
	insert(103, "OnGangDamageStateChange");
	insert(104, "OnLSC");
	insert(105, "OnSpecialFX");
	insert(106, "OnTarget");
	insert(107, "RemoveBalls");
	insert(108, "SendMessage");
	insert(109, "SetMaxSpeed");
	insert(110, "SetSpeedFraction");
	insert(111, "TerminalExplosion");
	insert(112, "address");
	insert(113, "alert");
	insert(114, "allianceID");
	insert(115, "allianceid");
	insert(116, "bid");
	insert(117, "bookmark");
	insert(118, "bounty");
	insert(119, "channel");
	insert(120, "charid");
	insert(121, "constellationid");
	insert(122, "corpID");
	insert(123, "corpid");
	insert(124, "corprole");
	insert(125, "damage");
	insert(126, "duration");
	insert(127, "effects.Laser");
	insert(128, "gangid");
	insert(129, "gangrole");
	insert(130, "hqID");
	insert(131, "issued");
	insert(132, "jit");
	insert(133, "languageID");
	insert(134, "locationid");
	insert(135, "machoVersion");
	insert(136, "marketProxy");
	insert(137, "minVolume");
	insert(138, "orderID");
	insert(139, "price");
	insert(140, "range");
	insert(141, "regionID");
	insert(142, "regionid");
	insert(143, "role");
	insert(144, "rolesAtAll");
	insert(145, "rolesAtBase");
	insert(146, "rolesAtHQ");
	insert(147, "rolesAtOther");
	insert(148, "shipid");
	insert(149, "sn");
	insert(150, "solarSystemID");
	insert(151, "solarsystemid");
	insert(152, "solarsystemid2");
	insert(153, "source");
	insert(154, "splash");
	insert(155, "stationID");
	insert(156, "stationid");
	insert(157, "target");
	insert(158, "userType");
	insert(159, "userid");
	insert(160, "volEntered");
	insert(161, "volRemaining");
	insert(162, "weapon");
	insert(163, "agent.missionTemplatizedContent_BasicKillMission");
	insert(164, "agent.missionTemplatizedContent_ResearchKillMission");
	insert(165, "agent.missionTemplatizedContent_StorylineKillMission");
	insert(166, "agent.missionTemplatizedContent_GenericStorylineKillMission");
	insert(167, "agent.missionTemplatizedContent_BasicCourierMission");
	insert(168, "agent.missionTemplatizedContent_ResearchCourierMission");
	insert(169, "agent.missionTemplatizedContent_StorylineCourierMission");
	insert(170,
			"agent.missionTemplatizedContent_GenericStorylineCourierMission");
	insert(171, "agent.missionTemplatizedContent_BasicTradeMission");
	insert(172, "agent.missionTemplatizedContent_ResearchTradeMission");
	insert(173, "agent.missionTemplatizedContent_StorylineTradeMission");
	insert(174, "agent.missionTemplatizedContent_GenericStorylineTradeMission");
	insert(175, "agent.offerTemplatizedContent_BasicExchangeOffer");
	insert(
			176,
			"agent.offerTemplatizedContent_BasicExchangeOffer_ContrabandDemand");
	insert(177, "agent.offerTemplatizedContent_BasicExchangeOffer_Crafting");
	insert(178, "agent.LoyaltyPoints");
	insert(179, "agent.ResearchPoints");
	insert(180, "agent.Credits");
	insert(181, "agent.Item");
	insert(182, "agent.Entity");
	insert(183, "agent.Objective");
	insert(184, "agent.FetchObjective");
	insert(185, "agent.EncounterObjective");
	insert(186, "agent.DungeonObjective");
	insert(187, "agent.TransportObjective");
	insert(188, "agent.Reward");
	insert(189, "agent.TimeBonusReward");
	insert(190, "agent.MissionReferral");
	insert(191, "agent.Location");
	insert(192, "agent.StandardMissionDetails");
	insert(193, "agent.OfferDetails");
	insert(194, "agent.ResearchMissionDetails");
	insert(195, "agent.StorylineMissionDetails");
	insert(196, "#196");
	insert(197, "#197");
	insert(198, "#198");
	insert(199, "#199");
	insert(200, "#200");
	insert(201, "#201");
	insert(202, "#202");
	insert(203, "#203");
	insert(204, "#204");
	insert(205, "#205");
	insert(206, "#206");
	insert(207, "#207");
	insert(208, "#208");
	insert(209, "#209");
	insert(210, "#210");
	insert(211, "#211");
	insert(212, "#212");
	insert(213, "#213");
	insert(214, "#214");
	insert(215, "#215");
	insert(216, "#216");
	insert(217, "#217");
	insert(218, "#218");
	insert(219, "#219");
	insert(220, "#220");
	insert(221, "#221");
	insert(222, "#222");
	insert(223, "#223");
	insert(224, "#224");
	insert(225, "#225");
	insert(226, "#226");
	insert(227, "#227");
	insert(228, "#228");
	insert(229, "#229");
	insert(230, "#230");
	insert(231, "#231");
	insert(232, "#232");
	insert(233, "#233");
	insert(234, "#234");
	insert(235, "#235");
	insert(236, "#236");
	insert(237, "#237");
	insert(238, "#238");
	insert(239, "#239");
	insert(240, "#240");
	insert(241, "#241");
	insert(242, "#242");
	insert(243, "#243");
	insert(244, "#244");
	insert(245, "#245");
	insert(246, "#246");
	insert(247, "#247");
	insert(248, "#248");
	insert(249, "#249");
	insert(250, "#250");
	insert(251, "#251");
	insert(252, "#252");
	insert(253, "#253");
	insert(254, "#254");
	insert(255, "#255");
}

void strings::insert(unsigned int id, std::string string) {
	m_strings[id] = string;
}

const std::string strings::get(unsigned int id) {
	init();
	return (m_strings[id]);
}

bool strings::has(unsigned int id) {
	init();
	return (m_strings.find(id) != m_strings.end());
}

} /* namespace marshal */

} /* namespace evetools */
