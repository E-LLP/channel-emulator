/* -*- C++ -*- */

//=============================================================================
/**
 * @file   modAOS_MC_Frame_Interface.cpp
 * @author Tad Kollar  
 *
 * $Id: modAOS_MC_Frame_Interface.cpp 1670 2012-08-28 13:25:28Z tkollar $
 * Copyright (c) 2010.
 *      NASA Glenn Research Center.  All rights reserved.
 *      See COPYING file that comes with this distribution.
 */
//=============================================================================

#include "modAOS_MC_Frame.hpp"
#include "AOS_Interface_Macros.hpp"
#include "PeriodicHandler_Interface.hpp"

namespace nAOS_MC_Frame {

//=============================================================================
/**
 * @class modAOS_MC_Frame_Interface
 * @author Tad Kollar  
 * @brief An XML-RPC interface to the AOS Virtual Channel Frame service module.
 */
//=============================================================================
class modAOS_MC_Frame_Interface: public nasaCE::PeriodicHandler_Interface<modAOS_MC_Frame> {
public:
	modAOS_MC_Frame_Interface(xmlrpc_c::registryPtr& rpcRegistry):
		nasaCE::PeriodicHandler_Interface<modAOS_MC_Frame>(rpcRegistry, "modAOS_MC_Frame") {
		ACE_TRACE("modAOS_MC_Frame_Interface::modAOS_MC_Frame_Interface");

		register_methods(rpcRegistry);
	}

	AOS_PHYSICAL_CHANNEL_DEFINE_ACCESSORS();
	AOS_MASTER_CHANNEL_DEFINE_ACCESSORS();

	/// Export specified methods via XML-RPC.
	void register_methods(xmlrpc_c::registryPtr&);

protected:
	void get_counters_(xmlrpc_c::paramList const& paramList, modAOS_MC_Frame* handler,
		xstruct& counters) {
		ACE_TRACE("modAOS_MC_Frame_Interface::get_counters_");

		nasaCE::TrafficHandler_Interface<modAOS_MC_Frame>::get_counters_(paramList, handler, counters);

		GET_AOS_PHYSICAL_CHANNEL_COUNTERS();
		GET_AOS_MASTER_CHANNEL_COUNTERS();
	}

	void get_settings_(xmlrpc_c::paramList const& paramList, modAOS_MC_Frame* handler,
		xstruct& settings) {
		ACE_TRACE("modAOS_MC_Frame_Interface::get_settings_");

		nasaCE::TrafficHandler_Interface<modAOS_MC_Frame>::get_settings_(paramList, handler, settings);

		GET_AOS_PHYSICAL_CHANNEL_SETTINGS();
		GET_AOS_MASTER_CHANNEL_SETTINGS();
	}
};

modAOS_MC_Frame_Interface* modAOS_MC_Frame_InterfaceP;

PERIODIC_METHOD_CLASSES(modAOS_MC_Frame_Interface, modAOS_MC_Frame_InterfaceP);
AOS_PHYSICAL_CHANNEL_GENERATE_METHODS(modAOS_MC_Frame_InterfaceP);
AOS_MASTER_CHANNEL_GENERATE_METHODS(modAOS_MC_Frame_InterfaceP);

void modAOS_MC_Frame_Interface::register_methods(xmlrpc_c::registryPtr& rpcRegistry) {
	ACE_TRACE("modAOS_MC_Frame_Interface::register_methods");

	PERIODIC_REGISTER_METHODS(modAOS_MC_Frame, modAOS_MC_Frame_Interface);
	AOS_PHYSICAL_CHANNEL_REGISTER_METHODS(modAOS_MC_Frame);
	AOS_MASTER_CHANNEL_REGISTER_METHODS(modAOS_MC_Frame);
}

} // namespace nAOS_MC_Frame
