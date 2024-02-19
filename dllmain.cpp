#include <random>
#include <windows.h>
#pragma warning(push, 0)
#include <cocos2d.h>
#pragma warning(pop)
#include "menubutton1.hpp"
#include "LoadingLayer.hpp"
#include "links.hpp"
#include "includes.h"
#include <windows.h>
#include <shellapi.h>
#include <MinHook.h>
#include <gd.h>
#include <ctime>

class EventoGDPS : public cocos2d::CCLayer {
public:
    void MostrarTexto(cocos2d::CCObject* pSender) {
        auto GM = gd::GameManager::sharedState();

        const char* mensaje = obtenerMensajeSegunFecha();
        gd::FLAlertLayer::create(nullptr, "GDPSWow", "ok", nullptr, mensaje)->show();
    }

    const char* obtenerMensajeSegunFecha() {
        // Obtén la fecha actual
        time_t now = time(0);
        struct tm* timeinfo = localtime(&now);

        // Verifica si es el 15 de abril
        if (timeinfo->tm_mon == 10 && timeinfo->tm_mday == 12) {
            // Es el 15 de abril, mensaje especial
            return "Hola como estan owo?";
        } else {
            // No es el 15 de abril, mensaje predeterminado
            return "No Todavia tenemos algo para usted";
        }
    }
};

bool (__thiscall* MenuLayer_init)(CCLayer* self);
bool __fastcall MenuLayer_init_H(CCLayer* self, void*) {

    if (!MenuLayer_init(self)) return false;

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto waos = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(3));

    auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png");
    
    auto button = gd::CCMenuItemSpriteExtra::create(
        buttonSprite,
        self,
        menu_selector(ToMorritowCode::switchToCustomLayerButton)
    );
    
    button->setPosition(-141, 0);
    button->setScale({1.125f});
    button->setZOrder(-1);
    waos->addChild(button);

    waos->setPosition(310, 42);

    auto ButtonChest = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(waos->getChildren()->objectAtIndex(4));

    ButtonChest->setPosition(222, 135);

    auto ToMorrtw = CCLabelBMFont::create("Mods Developer by ToMorritow", "bigFont.fnt");
    
    auto ToMorrtwbutton = gd::CCMenuItemSpriteExtra::create(
        ToMorrtw,
        self,
        menu_selector(ToMorritowLink::Discord)
    );

    auto wmenu = CCMenu::create();
    wmenu->addChild(ToMorrtwbutton);
    wmenu->setPosition(89, 197);
    wmenu->setScale({0.3f});
    self->addChild(wmenu);

    //Revolutions Mod

    auto SpritePlay = CCSprite::createWithSpriteFrameName("GJ_musicOnBtn_001.png");
    SpritePlay->setScale({1.0f});
    
    auto ButtonPlay = gd::CCMenuItemSpriteExtra::create(
        SpritePlay,
        self,
        menu_selector(EventoGDPS::MostrarTexto)
    );

    //ButtonPlay->setPosition(ButtonPlay->getContentSize().width / 2, 
    //                        winSize.height - ButtonPlay->getContentSize().height / 2);

    ButtonPlay->setPosition(winSize.width - ButtonPlay->getContentSize().width / 2, 
                        winSize.height - ButtonPlay->getContentSize().height / 2);

    auto MenuPlay = CCMenu::create();
    MenuPlay->addChild(ButtonPlay);
    MenuPlay->setPosition(-10, -10);
    self->addChild(MenuPlay);


    return true;
}

/*
const char* (__thiscall* LoadingLayer_getString_org)(LoadingLayer*);
const char* __fastcall LoadingLayer_getString_h(LoadingLayer* self, void*) {

    const char* s[1] = {
        "Bienvenido <cr>uwu</c>",
    };

    srand(time(NULL));

    return s[rand() % 1];
}
*/
/*
const char* (__thiscall* LoadingLayer_getString_org)(LoadingLayer*);
const char* __fastcall LoadingLayer_getString_h(LoadingLayer* self, void*) {

    auto t = std::time(nullptr);
    auto tmp = std::localtime(&t);

    if (tmp != nullptr) {
        // Enero 1
        if (tmp->tm_mday == 1 && tmp->tm_mon == 1) {
            return "Feliz Año Nuevo :D!!!";
        }

         // 14 de febrero
        if (tmp->tm_mday == 14 && tmp->tm_mon == 1) {
            return "Feliz día de San Valentín Comunidad :D!";
        }

        // abril 15 - mi cumpleaños XD
        if (tmp->tm_mday == 15 && tmp->tm_mon == 3) {
            return "Feliz cumple ToMorritow :D!!";
        }

        // Octubre 31
        if (tmp->tm_mday == 31 && tmp->tm_mon == 10) {
            return "Feliz Halloween Owo!";
        }

        // Diciembre 24
        if (tmp->tm_mday == 24 && tmp->tm_mon == 12) {
            return "Feliz Navidad Gente .D!";
        }

        // Diciembre 31
        if (tmp->tm_mday == 31 && tmp->tm_mon == 12) {
            return "Poco para 2024 >w<!.";
        }

        // TestXD
        if (tmp->tm_mday == 12 && tmp->tm_mon == 11) {
            return "mi Testeo uwu";
        }
    }

    char time_str[64];
    std::strftime(time_str, sizeof(time_str), "%c", tmp);

    const char* messages[] = {
        "Recuerda leer las reglas >w<!",
        "Asegurate de unirte al servidor de Discord owo",
        "Bienvenido al GDPS uwu",
        "Sin ningun hacker por aqui...",
        "Bienvenido Aventurero OwO",
        "Ehh h bos bosteas el Servidor de Discord qwq!?...",
        "ToMorritow mi Jefe es muy amable pwp",
        "Te aseguro que no entraste al Servidor de Discord unu",
        time_str
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, sizeof(messages) / sizeof(messages[0]) - 1);

    auto chosen_index = dist(gen);
    return messages[chosen_index];
}
*/

enum Meses {
    ENERO = 0,
    FEBRERO = 1,
    MARZO = 2,
    ABRIL = 3,
    MAYO = 4,
    JUNIO = 5,
    JULIO = 6,
    AGOSTO = 7,
    SEPTIEMBRE = 8,
    OCTUBRE = 9,
    NOVIEMBRE = 10,
    DICIEMBRE = 11
};

const char* obtenerMensajeDelDia(std::tm* tmp) {

    std::vector<std::pair<std::tm, const char*>> fechasEspeciales = {
        {{0, 0, 0, 1, 1, 0}, "Feliz Ano Nuevo :D!!!"},
        {{0, 0, 0, 14, 1, 0}, "Feliz dia de San Valentin Comunidad :D!"},
        {{0, 0, 0, 15, 3, 0}, "Feliz cumple ToMorritow :D!!"},
        {{0, 0, 0, 31, 10, 0}, "Feliz Halloween Owo!"},
        {{0, 0, 0, 24, 12, 0}, "Feliz Navidad Gente .D!"},
        {{0, 0, 0, 31, 12, 0}, "Poco para 2024 >w<!."},
        {{0, 0, 0, 12, 11, 0}, "Testeo XD"}
    };

    for (const auto& fecha : fechasEspeciales) {
        if (tmp != nullptr && std::memcmp(tmp, &fecha.first, sizeof(std::tm)) == 0) {
            return fecha.second;
        }
    }

    return nullptr;
}

const char* obtenerMensajeAleatorio() {
    const char* messages[] = {
        "Recuerda leer las reglas >w<!",
        "Asegurate de unirte al servidor de Discord owo",
        "Bienvenido al GDPS uwu",
        "Sin ningun hacker por aqui...",
        "Bienvenido Aventurero OwO",
        "Ehh h bos bosteas el Servidor de Discord qwq!?...",
        "ToMorritow mi Jefe es muy amable pwp",
        "Te aseguro que no entraste al Servidor de Discord unu"
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, sizeof(messages) / sizeof(messages[0]) - 1);

    auto chosen_index = dist(gen);
    return messages[chosen_index];
}

const char* (__thiscall* LoadingLayer_getString_org)(LoadingLayer*);
const char* __fastcall LoadingLayer_getString_h(LoadingLayer* self, void*) {

    auto t = std::time(nullptr);
    auto tmp = std::localtime(&t);

    const char* mensajeEspecial = obtenerMensajeDelDia(tmp);
    if (mensajeEspecial != nullptr) {
        const char* mensajeAleatorio = obtenerMensajeAleatorio();
        char* mensajeCombinado = new char[strlen(mensajeEspecial) + strlen(mensajeAleatorio) + 1];
        strcpy(mensajeCombinado, mensajeEspecial);
        strcat(mensajeCombinado, mensajeAleatorio);
        return mensajeCombinado;
    }

    return obtenerMensajeAleatorio();
}

DWORD WINAPI thread_func(void* hModule) {

    MH_Initialize();

    auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
    
    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x1907b0),
        reinterpret_cast<void*>(&MenuLayer_init_H),
        reinterpret_cast<void**>(&MenuLayer_init)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x18cf40),
        reinterpret_cast<void*>(&LoadingLayer_getString_h),
        reinterpret_cast<void**>(&LoadingLayer_getString_org)
    );

    MH_EnableHook(MH_ALL_HOOKS);

    return 0;
}

/*
This function runs whenever we inject our dll, this is present
in pretty much every mod, and is just winapi boilerplate
*/
BOOL APIENTRY DllMain(HMODULE handle, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        auto h = CreateThread(0, 0, thread_func, handle, 0, 0);
        if (h)
            CloseHandle(h);
        else
            return FALSE;
    }
    return TRUE;
}