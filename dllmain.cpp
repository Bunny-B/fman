// dllmain.cpp : Définit le point d'entrée de l'application DLL.
#include <ida.hpp>
#include <idp.hpp>

#include <loader.hpp>
#include <search.hpp>

#include <kernwin.hpp>

#define PLUGIN_NAME				"FMAN"//find me a name
#define VERSION				"V0.0.2"


struct plugin_ctx_t : public plugmod_t {
    ~plugin_ctx_t() {
    }
    virtual bool idaapi run(size_t) override { return true; };//PLUGIN_MULTI 
};

static plugmod_t* idaapi init() {
    msg("Initializing %s plugin...\n", PLUGIN_NAME);
    return new plugin_ctx_t;
}

static bool idaapi run(size_t arg) {
    msg("run Name 2: %s%s\n", PLUGIN_NAME, VERSION);
    
    return true;
}


// The plugin description block
plugin_t PLUGIN = {
    IDP_INTERFACE_VERSION, // IDA's version
    PLUGIN_UNL   ,            // Plugin flags
    init,                  // Initialize
    nullptr,                  // Terminate
    run,                   // Execute Must be nullptr for PLUGIN_MULTI plugins 
    PLUGIN_NAME,       // Comment
    "Empty Space",         // Help
    PLUGIN_NAME,            // Plugin name
    "Ctrl+Shift+H"           // Hotkey
};
