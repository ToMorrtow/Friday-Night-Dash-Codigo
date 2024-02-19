#include "includes.h"
#include "menubutton1.hpp"
#include <windows.h>
#include <shellapi.h>
#include <MinHook.h>
#include <gd.h>
#include <windows.h>
#pragma warning(push, 0)
#include <cocos2d.h>
#pragma warning(pop)
#include <string>

ToMorritowCode* ToMorritowCode::create() {
    auto ret = new ToMorritowCode();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool ToMorritowCode::init() {

    auto Personaje1 = CCSprite::create("dialogIcon_001.png");
    Personaje1->setPosition({100, 100});
    Personaje1->setSkewX({12});
    //addChild(Personaje1);

    auto Personaje2 = CCSprite::create("dialogIcon_002.png");
    Personaje2->setPosition({486, 100});
    Personaje2->setSkewX({-12});
    //addChild(Personaje2);

    auto Personaje3 = CCSprite::create("dialogIcon_004.png");
    Personaje3->setPosition({277, 100});
    //addChild(Personaje3);

    auto Flash = CCSprite::create("GJ_bigStar_glow_001.png");
    Flash->setPosition({284, 100});
    Flash->setZOrder(5);
    Flash->setScale(31.475f);
    //addChild(Flash);

    Flash->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2, 0), CCFadeTo::create(2, 0), nullptr)));

    auto LogoTexto = CCLabelBMFont::create("Friday Night Dash", "bigFont.fnt");
    LogoTexto->setPosition({290, 263});
    //addChild(LogoTexto);

    LogoTexto->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCScaleTo::create(1.0f, 1.05f)), 
    CCEaseSineInOut::create(CCScaleTo::create(1.0, 1.0f)), nullptr)));

    auto VersionTexto = CCLabelBMFont::create("version 0.2", "bigFont.fnt");
    VersionTexto->setPosition({409, 237});
    VersionTexto->setScale({0.325f});
    //addChild(VersionTexto);

    VersionTexto->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(3, 180), CCFadeTo::create(3, 110), nullptr)));

    auto Suelo = CCSprite::create("groundSquare_01_001.png");
    Suelo->setPosition({505, -4.300});
    Suelo->setColor({0, 102, 255});

    //addChild(Suelo);

    auto Suelo2 = CCSprite::create("groundSquare_01_001.png");
    Suelo2->setPosition({377.820, -4.300});
    Suelo2->setColor({0, 102, 255});
    //addChild(Suelo2);

    auto Suelo3 = CCSprite::create("groundSquare_01_001.png");
    Suelo3->setPosition({249.940, -4.300});
    Suelo3->setColor({0, 102, 255});
    //addChild(Suelo3);

    auto Suelo4 = CCSprite::create("groundSquare_01_001.png");
    Suelo4->setPosition({122.350, -4.300});
    Suelo4->setColor({0, 102, 255});
    //addChild(Suelo4);

    auto Suelo5 = CCSprite::create("groundSquare_01_001.png");
    Suelo5->setPosition({-5.550, -4.300});
    Suelo5->setColor({0, 102, 255});

    auto Suelo6 = CCSprite::create("groundSquare_01_001.png");
    Suelo6->setPosition({-127.900, -4.300});
    Suelo6->setColor({0, 102, 255});

    auto Suelo7 = CCSprite::create("groundSquare_01_001.png");
    Suelo7->setPosition({632.9, -4.300});
    Suelo7->setColor({0, 102, 255});
    //addChild(Suelo5);

    //Extras
    
    auto backgroundSprite = CCSprite::create("game_bg_01_001.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();
    
    backgroundSprite->setColor({40, 125, 255});
    
    backgroundSprite->setZOrder(-1);
    backgroundSprite->setScale({1.181f});
    backgroundSprite->setPosition({283.230, 300.5});

    //addChild(backgroundSprite);

    gd::GameManager::sharedState()->fadeInMusic("menuLoopSai.mp3");

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(LayerListFNF::switchToCustomLayerButton)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    menu->setZOrder(1);
    addChild(menu);

    auto FFlashSprite = CCSprite::create("game_bg_01_001.png");
    FFlashSprite->setPosition({300, 20});
    FFlashSprite->setScale({1.181f});
    FFlashSprite->setColor({0, 0, 0});
    FFlashSprite->setZOrder(1);
    addChild(FFlashSprite);

    FFlashSprite->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCFadeTo::create(1.7, (0, 120))),
    CCEaseSineInOut::create(CCFadeTo::create(1, 0)), nullptr)));


    //setKeypadEnabled(true);

    auto BackgroundMenu = CCMenu::create();
    BackgroundMenu->setPosition({0, 0});
    BackgroundMenu->addChild(backgroundSprite);

    auto menumove = CCMenu::create();
    menumove->addChild(BackgroundMenu);
    menumove->addChild(Personaje1);
    menumove->addChild(Personaje2);
    menumove->addChild(Personaje3);
    menumove->addChild(LogoTexto);
    menumove->addChild(VersionTexto);
    menumove->addChild(Suelo);
    menumove->addChild(Suelo2);
    menumove->addChild(Suelo3);
    menumove->addChild(Suelo4);
    menumove->addChild(Suelo5);
    menumove->addChild(Suelo6);
    menumove->addChild(Suelo7);
    menumove->setPosition({0, 0});
    //addChild(menumove);

    menumove->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCMoveTo::create(1, {0, 2})),
    CCEaseSineInOut::create(CCMoveTo::create(1, {0, 0})), nullptr)));

    auto menumoveY = CCMenu::create();
    menumoveY->addChild(menumove);
    menumoveY->setPosition({0, 0});
    addChild(menumoveY);

    menumoveY->runAction(CCRepeatForever::create(CCSequence::create(
	CCTintTo::create(3, 100, 100, 100), 
	CCTintTo::create(4, 255, 255, 255), nullptr)));

    menumove->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {2, 0})), 
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {-1, 0})), nullptr)));

    auto GM = gd::GJAccountManager::sharedState();
    std::string Nombre = GM->m_sUsername;
    std::string mensaje = "Hola " + Nombre + " uwu";
    auto bienvenida = CCLabelBMFont::create(mensaje.c_str(), "bigFont.fnt");
    bienvenida->setPosition({92, 13.6});
    bienvenida->setScale({0.421f});
    bienvenida->setZOrder(2);
    addChild(bienvenida);

    return true;
}

void ToMorritowCode::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void ToMorritowCode::switchToCustomLayerButton(CCObject* object) {
    auto layer = ToMorritowCode::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->pushScene(transition);
}

/// Layer 2

LayerListFNF* LayerListFNF::create() {
    auto ret = new LayerListFNF();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

void LayerListFNF::Alert1(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "Desarrollo", "ok", nullptr, "Esta en Desarrollo.");
    flalert->show();
}

void LayerListFNF::Version(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "ToMorritow", "ok", nullptr, "Version 0.2");
    flalert->show();
}

bool LayerListFNF::init() {
    
    auto CreateSprite = CCSprite::createWithSpriteFrameName("GJ_challengeBtn_001.png");

    auto Createbutton = gd::CCMenuItemSpriteExtra::create(
        CreateSprite,
        this,
        menu_selector(LayerListFNF::Alert1)
    );

    CreateSprite->setColor({100, 100, 100});

    auto LevelsOnlineSprite = CCSprite::createWithSpriteFrameName("GJ_searchBtn_001.png");

    auto Levelbutton = gd::CCMenuItemSpriteExtra::create(
        LevelsOnlineSprite,
        this,
        menu_selector(LayerListFNF::Scene1)
    );

    auto TheMapSprite = CCSprite::createWithSpriteFrameName("GJ_weeklyBtn_001.png");

    auto Mapbutton = gd::CCMenuItemSpriteExtra::create(
        TheMapSprite,
        this,
        menu_selector(LayerListFNF::Alert1)
    );

    //TheMapSprite->setColor({100, 100, 100});

    auto PartsSprite = CCSprite::createWithSpriteFrameName("GJ_createBtn_001.png");

    auto Partsbutton = gd::CCMenuItemSpriteExtra::create(
        PartsSprite,
        this,
        menu_selector(LayerListFNF::Alert1)
    );

    PartsSprite->setColor({100, 100, 100});

    auto InfoSprite = CCSprite::createWithSpriteFrameName("GJ_infoBtn_001.png");

    auto Infobutton = gd::CCMenuItemSpriteExtra::create(
        InfoSprite,
        this,
        menu_selector(LayerListFNF::Version)
    );

    auto CreditosSprite = CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png");

    auto Creditosbutton = gd::CCMenuItemSpriteExtra::create(
        CreditosSprite,
        this,
        menu_selector(CreditosLayer::switchToCustomLayerButton)
    );

    Createbutton->setPosition({230, 205});
    Levelbutton->setPosition({356, 205});
    Mapbutton->setPosition({229, 95});
    Partsbutton->setPosition({356, 95});
    Infobutton->setPosition({40, 30});
    Creditosbutton->setPosition({556, 295});

    Infobutton->setZOrder(1);
    Creditosbutton->setZOrder(1);
    

    //auto StoryModeLabel = CCSprite::createWithSpriteFrameName("StoryMode_01_001.png");
    //StoryModeLabel->setScale(1.5f);
    //StoryModeLabel->setTag(5);

    //auto FreePlayLabel = CCSprite::createWithSpriteFrameName("FreePlay_01_001.png");
    //FreePlayLabel->setScale(1.5f);
    //FreePlayLabel->setColor({ 100, 100, 100 });

    //auto CreditsLabel = CCSprite::createWithSpriteFrameName("Credits_01_001.png");
    //CreditsLabel->setScale(1.5f);
    //CreditsLabel->setColor({ 100, 100, 100 });

    //auto OptionsLabel = CCSprite::createWithSpriteFrameName("Options_01_001.png");
    //OptionsLabel->setScale(1.5f);
    //OptionsLabel->setColor({ 100, 100, 100 });

    //auto StoryModeLabel = CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png");
    //auto FreePlayLabel = CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png");
    //auto CreditsLabel = CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png");
    //auto OptionsLabel = CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png");
    
    //auto StoryModeBotton = gd::CCMenuItemSpriteExtra::create(
    //    StoryModeLabel,
    //    this,
    //    menu_selector(LayerListFNF::Scene1)
    //);

    //auto FreePlayBotton = gd::CCMenuItemSpriteExtra::create(
    //    StoryModeLabel,
    //    this,
    //    menu_selector(MenuSelectorTM::switchToCustomLayerButton)
    //);

    //auto CreditsBotton = gd::CCMenuItemSpriteExtra::create(
    //    StoryModeLabel,
    //    this,
    //    menu_selector(MenuSelectorTM::switchToCustomLayerButton)
    //);

    //auto OptionsBotton = gd::CCMenuItemSpriteExtra::create(
    //    StoryModeLabel,
    //    this,
    //    menu_selector(MenuSelectorTM::switchToCustomLayerButton)
    //);

    //StoryModeBotton->setPosition({285, 255});
    //FreePlayBotton->setPosition({285, 172});
    //CreditsBotton->setPosition({285, 1000});
    //OptionsBotton->setPosition({285, 75});
    

    auto generalmenu = CCMenu::create();
    generalmenu->addChild(Createbutton);
    generalmenu->addChild(Levelbutton);
    generalmenu->addChild(Mapbutton);
    generalmenu->addChild(Partsbutton);
    generalmenu->addChild(Infobutton);
    //generalmenu->addChild(StoryModeBotton);
    //generalmenu->addChild(FreePlayBotton);
    //generalmenu->addChild(CreditsBotton);
    //generalmenu->addChild(OptionsBotton);
    generalmenu->setPosition({0, 0});
    generalmenu->setZOrder(1);
    addChild(generalmenu);
    

    
    auto otromenu = CCMenu::create();
    otromenu->addChild(Creditosbutton);
    otromenu->setPosition({74, 45});
    otromenu->setZOrder(1);
    otromenu->setScale({0.675f});
    addChild(otromenu);
    

    //side art
    
    auto sideArt = CCSprite::create("GJ_sideArt_001.png");
    sideArt->setPosition({534 , 34});
    sideArt->setScale(1.0f);
    sideArt->setScaleX(-1.0f);
    addChild(sideArt);

    auto sideArt2 = CCSprite::create("GJ_sideArt_001.png");
    sideArt2->setPosition({35 , 34});
    sideArt2->setScale(1.0f);
    addChild(sideArt2);
    

    auto backgroundSprite = CCSprite::create("menuDesat.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    backgroundSprite->setTag(5);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({223, 96, 151});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(MenuINICIOFNF::switchToCustomLayerButton)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    return true;
}

void LayerListFNF::Scene1(CCObject*) {
    //gd::GameManager::sharedState()->fadeInMusic("menuLoopSai.mp3");
    this->runAction(CCSequence::create(CCDelayTime::create(0.7f), CCCallFuncO::create(this, callfuncO_selector(MenuSelectorTM::switchToCustomLayerButton), this), nullptr));
}

void LayerListFNF::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}


void LayerListFNF::switchToCustomLayerButton(CCObject* object) {
    auto layer = LayerListFNF::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

// Layer Inicio Mod -> MenuInicio FNF

MenuINICIOFNF* MenuINICIOFNF::create() {
    auto ret = new MenuINICIOFNF();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool MenuINICIOFNF::init() {

    auto Flash = CCSprite::create("GJ_bigStar_glow_001.png");
    Flash->setPosition({284, 100});
    Flash->setZOrder(5);
    Flash->setScale(31.475f);
    Flash->setBlendFunc({ GL_SRC_ALPHA, GL_ONE });
    addChild(Flash);

    Flash->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2, 0), CCFadeTo::create(2, 0), nullptr)));

    auto VersionTexto = CCLabelBMFont::create("Mod by ToMorritow", "bigFont.fnt");
    VersionTexto->setPosition({280, 100});
    VersionTexto->setScale({0.3f});
    addChild(VersionTexto);

    auto LogoMenu = CCSprite::create("FNF_logo.png");
    LogoMenu->setPosition({290, 180});
    LogoMenu->setScale({1.480f});
    addChild(LogoMenu);

    LogoMenu->runAction(CCRepeatForever::create(CCSequence::create(CCRotateTo::create(2, 3), CCRotateTo::create(2, -3), nullptr)));

    LogoMenu->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseExponentialInOut::create(CCScaleTo::create(1.1f, 1.15f)), 
    CCEaseExponentialInOut::create(CCScaleTo::create(0.5, 1.2f)), nullptr)));
    
    auto backgroundSprite = CCSprite::create("game_bg_01_001.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({0, 0, 0});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    gd::GameManager::sharedState()->fadeInMusic("menuLoopSai.mp3");

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Prees Click To Begin", "bigFont.fnt"),
        this,
        menu_selector(LayerListFNF::switchToCustomLayerButton)
    );

    button->setScale({0.800f});

    button->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCScaleTo::create(1.0f, 1.05f)), 
    CCEaseSineInOut::create(CCScaleTo::create(1.0, 1.0f)), nullptr)));

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({220, -2});
    menu->setScale({0.750f});

    addChild(menu);

    return true;
}

void MenuINICIOFNF::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}


void MenuINICIOFNF::switchToCustomLayerButton(CCObject* object) {
    auto layer = MenuINICIOFNF::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

// Layer 3 -> MenuSelector

MenuSelectorTM* MenuSelectorTM::create() {
    auto ret = new MenuSelectorTM();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

void MenuSelectorTM::Nivel1(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "ToMorritow", "ok", nullptr, "Estas en el <cy>nivel 1</c>");
    flalert->show();
}

void MenuSelectorTM::Nivel2(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "ToMorritow", "ok", nullptr, "No todavia hecho.");
    flalert->show();
}

bool MenuSelectorTM::init() {

    auto textBg = CCSprite::create("square02_001.png");
	textBg->setPosition({285, 158});
	textBg->setOpacity(60);
	textBg->setScaleX({6.390});
	textBg->setScaleY({3.158});

    auto SpriteBackgroundw = CCSprite::create("square02_001.png");
	SpriteBackgroundw->setPosition({349, 159});
	SpriteBackgroundw->setOpacity(60);
	SpriteBackgroundw->setScaleX({4.490});
	SpriteBackgroundw->setScaleY({2.865});

    auto SpriteBackgroundw2 = CCSprite::create("square02_001.png");
	SpriteBackgroundw2->setPosition({290.1, 142.55});
	SpriteBackgroundw2->setOpacity(60);
	SpriteBackgroundw2->setScaleX({2.632});
	SpriteBackgroundw2->setScaleY({2.146});

    auto SpriteLevel01 = CCSprite::create("square02_001.png");
	SpriteLevel01->setPosition({100, 246});
	SpriteLevel01->setOpacity(60);
	SpriteLevel01->setScaleX({1.465});
	SpriteLevel01->setScaleY({0.540});

    auto SpriteLevel02 = CCSprite::create("square02_001.png");
	SpriteLevel02->setPosition({100, 194.870});
	SpriteLevel02->setOpacity(60);
	SpriteLevel02->setScaleX({1.465});
	SpriteLevel02->setScaleY({0.540});

    auto Nivel01Label = CCLabelBMFont::create("Nivel 1", "bigFont.fnt");
    auto Nivel02Label = CCLabelBMFont::create("Nivel 2", "bigFont.fnt");
    auto NivelesLabel = CCLabelBMFont::create("Niveles Principales", "bigFont.fnt");
    auto HardLabel = CCLabelBMFont::create("Hard", "bigFont.fnt");
    auto VsLabel = CCLabelBMFont::create("Vs Miguelito", "bigFont.fnt");
    auto PlayLabel = CCLabelBMFont::create("Play", "bigFont.fnt");

    auto BottonNivel01 = gd::CCMenuItemSpriteExtra::create(
        Nivel01Label,
        this,
        menu_selector(MenuSelectorTM::Nivel1)
    );

    auto BottonNivel02 = gd::CCMenuItemSpriteExtra::create(
        Nivel02Label,
        this,
        menu_selector(MenuSelectorTM::Nivel2)
    );

    auto PlayButton = gd::CCMenuItemSpriteExtra::create(
        PlayLabel,
        this,
        menu_selector(LoadingSpr1::switchToCustomLayerButton)
    );

    BottonNivel01->setPosition(101 , 247);
    BottonNivel02->setPosition(101 , 195.5);
    NivelesLabel->setPosition(360.14 , 256.5);
    HardLabel->setPosition(338 , 177.3);
    VsLabel->setPosition(282 , 205);
    PlayButton->setPosition(457.2, 151.8);

    Nivel01Label->setScale({0.55f});
    Nivel02Label->setScale({0.55f});
    NivelesLabel->setScale({0.766f});
    VsLabel->setScale({0.655f});
    HardLabel->setScale({0.655f});
    PlayLabel->setScale({1.082f});

    PlayLabel->setColor({0, 255, 0});

    auto MenuMove = CCMenu::create();
    MenuMove->addChild(textBg);
    MenuMove->addChild(SpriteBackgroundw);
    MenuMove->addChild(SpriteBackgroundw2);
    MenuMove->addChild(SpriteLevel01);
    MenuMove->addChild(SpriteLevel02);

    MenuMove->addChild(BottonNivel01);
    MenuMove->addChild(BottonNivel02);
    MenuMove->addChild(NivelesLabel);
    MenuMove->addChild(HardLabel);
    MenuMove->addChild(VsLabel);
    MenuMove->addChild(PlayButton);


    MenuMove->setPosition(0 , 0);
    MenuMove->setScale(1.0f);
    addChild(MenuMove);

    MenuMove->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCMoveTo::create(2, {0, 2})),
    CCEaseSineInOut::create(CCMoveTo::create(3, {0, -2})), nullptr)));

    //Niveles
    /*
    auto Level1Button = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Level 1", "bigFont.fnt"),
        this,
        menu_selector(LoadingSpr1::switchToCustomLayerButton)
    );

    Level1Button->setPosition({-50, 51});

    auto Level2Button = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Level 2", "bigFont.fnt"),
        this,
        menu_selector(LayerListFNF::Alert1)
    );

    Level2Button->setPosition({290, 51});

    auto Level3Button = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Level 3", "bigFont.fnt"),
        this,
        menu_selector(LayerListFNF::Alert1)
    );

    Level3Button->setPosition({641, 51});

    auto NievelesMenu = CCMenu::create();
    NievelesMenu->addChild(Level1Button);
    NievelesMenu->addChild(Level2Button);
    NievelesMenu->addChild(Level3Button);
    NievelesMenu->setPosition(0, 0);
    NievelesMenu->setScale({0.5f});
    addChild(NievelesMenu);
    */

    auto sideArt1 = CCSprite::create("GJ_sideArt_001.png");
    sideArt1->setPosition({35 , 34});
    sideArt1->setScale(1.0f);
    addChild(sideArt1);

    auto sideArt2 = CCSprite::create("GJ_sideArt_001.png");
    sideArt2->setPosition({34 , 285});
    sideArt2->setScale(1.0f);
    sideArt2->setScaleY(-1.0f);
    addChild(sideArt2);
    
    auto backgroundSprite = CCSprite::create("menuDesat.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({100, 100, 100});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(LayerListFNF::switchToCustomLayerButton)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    gd::GameManager::sharedState()->fadeInMusic("menuLoopSai.mp3");

    return true;
}

void MenuSelectorTM::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}


void MenuSelectorTM::switchToCustomLayerButton(CCObject* object) {
    auto layer = MenuSelectorTM::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

// Layer 4 -> Loading Layer

LoadingSpr1* LoadingSpr1::create() {
    auto ret = new LoadingSpr1();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool LoadingSpr1::init() {

    //Niveles
    
    //auto LoadingMenuFNF = CCMenu::create();
    //LoadingMenuFNF->addChild(SkipButton);
    //LoadingMenuFNF->setPosition(0, 0);
    //LoadingMenuFNF->setScale({0.475f});
    //addChild(LoadingMenuFNF);

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto label = CCLabelBMFont::create("Loading Assets...", "bigFont.fnt");
    label->setPosition({ winSize.width / 2, winSize.height / 2 });
    this->addChild(label);
    
    auto backgroundSprite = CCSprite::create("menuLoading2.png");

    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    backgroundSprite->setColor({43, 43, 43});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    backgroundSprite->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCTintTo::create(2.5, 43,   43,	  43)),
    CCEaseSineInOut::create(CCTintTo::create(2.0, 29,   44,	  51)), nullptr)));

    this->runAction(CCSequence::create(CCDelayTime::create(7.0f), CCCallFuncO::create(this, callfuncO_selector(Dialogue1::switchToCustomLayerButton), this), nullptr));

    return true;
}


void LoadingSpr1::switchToCustomLayerButton(CCObject* object) {
    auto layer = LoadingSpr1::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(1.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

// Layer 4 Dialogue 1

Dialogue1* Dialogue1::create() {
    auto ret = new Dialogue1();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool Dialogue1::init() {

    auto backgroundSprite = CCSprite::create("menuDialogue.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    backgroundSprite->setColor({0, 0, 0});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    this->runAction(CCSequence::create(CCDelayTime::create(7.0f), CCCallFuncO::create(this, callfuncO_selector(Dialogue1::switchToCustomLayerButton), this), nullptr));

    gd::GameManager::sharedState()->fadeInMusic("breakfast.mp3");

    return true;
}

void Dialogue1::switchToCustomLayerButton(CCObject* object) {
    auto layer = Dialogue1::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

// Layer 5 Dialogue 2

Dialogue2* Dialogue2::create() {
    auto ret = new Dialogue2();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool Dialogue2::init() {

    auto DialoguePers1 = CCSprite::create("GDG_reporteroIcon_001.png");
    DialoguePers1->setPosition({86, 170});
    DialoguePers1->setScaleX({-1.2f});
    DialoguePers1->setScaleY({1.2f});
    addChild(DialoguePers1);

    DialoguePers1->setColor({0, 0, 0});

    DialoguePers1->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseExponentialInOut::create(CCMoveTo::create(1, {85, 170})), 
    CCEaseExponentialInOut::create(CCMoveTo::create(1, {130, 170})), nullptr)));

    auto DialogueSpr = CCSprite::create("DialogueButton.png");
    DialogueSpr->setPosition({289, 70});
    DialogueSpr->setScaleX({6.800f});
    DialogueSpr->setScaleY({1.500f});
    addChild(DialogueSpr);

    //Skip

    auto Skip = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Continuar", "bigFont.fnt"),
        this,
        menu_selector(Dialogue3::switchToCustomLayerButton)
    );

    Skip->setPosition({631, 74});

    auto DialogueMenu = CCMenu::create();
    DialogueMenu->addChild(Skip);
    DialogueMenu->setPosition(0, 0);
    DialogueMenu->setScale({0.5f});
    addChild(DialogueMenu);

    auto Texto1 = CCLabelBMFont::create("W", "bigFont.fnt");
    Texto1->setPosition({68, 100});
    addChild(Texto1);

    auto Texto2 = CCLabelBMFont::create("a", "bigFont.fnt");
    Texto2->setPosition({86, 100});
    addChild(Texto2);

    auto Texto3 = CCLabelBMFont::create("o", "bigFont.fnt");
    Texto3->setPosition({103, 100});
    addChild(Texto3);

    auto Texto4 = CCLabelBMFont::create("s", "bigFont.fnt");
    Texto4->setPosition({120, 100});
    addChild(Texto4);

    Texto1->setScale({0.7f});
    Texto2->setScale({0.7f});
    Texto3->setScale({0.7f});
    Texto4->setScale({0.7f});

    Texto1->setOpacity(0.0f);
    Texto2->setOpacity(0.0f);
    Texto3->setOpacity(0.0f);
    Texto4->setOpacity(0.0f);

    Texto1->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2, 200), CCFadeTo::create(2, 200), nullptr)));
    Texto2->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.5, 200), CCFadeTo::create(2.5, 200), nullptr)));
    Texto3->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(3.0, 200), CCFadeTo::create(3.0, 200), nullptr)));
    Texto4->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(3.5, 200), CCFadeTo::create(3.5, 200), nullptr)));

    auto Flash = CCSprite::create("GJ_bigStar_glow_001.png");
    Flash->setPosition({284, 100});
    Flash->setZOrder(5);
    Flash->setScale(31.475f);
    addChild(Flash);

    Flash->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2, 0), CCFadeTo::create(2, 0), nullptr)));

    auto backgroundSprite = CCSprite::create("menuDialogue.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    gd::GameManager::sharedState()->fadeInMusic("breakfast.ogg");

    return true;
}

void Dialogue2::switchToCustomLayerButton(CCObject* object) {
    auto layer = Dialogue2::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

// Layer 6 Dialogue 3

Dialogue3* Dialogue3::create() {
    auto ret = new Dialogue3();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool Dialogue3::init() {

    auto DialoguePers1 = CCSprite::create("GDG_reporteroIcon_001.png");
    DialoguePers1->setPosition({86, 170});
    DialoguePers1->setScaleX({-1.2f});
    DialoguePers1->setScaleY({1.2f});
    addChild(DialoguePers1);

    DialoguePers1->setColor({0, 0, 0});

    DialoguePers1->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseExponentialInOut::create(CCMoveTo::create(1, {85, 170})), 
    CCEaseExponentialInOut::create(CCMoveTo::create(1, {130, 170})), nullptr)));

    auto DialogueSpr = CCSprite::create("DialogueButton.png");
    DialogueSpr->setPosition({289, 70});
    DialogueSpr->setScaleX({6.800f});
    DialogueSpr->setScaleY({1.500f});
    addChild(DialogueSpr);

    //Skip

    auto Skip = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Continuar", "bigFont.fnt"),
        this,
        menu_selector(Dialogue4::switchToCustomLayerButton)
    );

    Skip->setPosition({631, 74});

    auto DialogueMenu = CCMenu::create();
    DialogueMenu->addChild(Skip);
    DialogueMenu->setPosition(0, 0);
    DialogueMenu->setScale({0.5f});
    addChild(DialogueMenu);

    auto Texto1 = CCLabelBMFont::create("Yo", "bigFont.fnt");
    Texto1->setPosition({68, 100});
    addChild(Texto1);

    auto Texto2 = CCLabelBMFont::create("soy...", "bigFont.fnt");
    Texto2->setPosition({114, 100});
    addChild(Texto2);

    Texto1->setScale({0.7f});
    Texto2->setScale({0.7f});

    Texto1->setOpacity(0.0f);
    Texto2->setOpacity(0.0f);

    Texto1->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2, 200), CCFadeTo::create(2, 200), nullptr)));
    Texto2->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.5, 200), CCFadeTo::create(2.5, 200), nullptr)));

    auto Flash = CCSprite::create("GJ_bigStar_glow_001.png");
    Flash->setPosition({284, 100});
    Flash->setZOrder(5);
    Flash->setScale(31.475f);
    Flash->setColor({0, 0, 0});
    addChild(Flash);

    Flash->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2, 0), CCFadeTo::create(2, 0), nullptr)));

    auto backgroundSprite = CCSprite::create("menuDialogue.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    gd::GameManager::sharedState()->fadeInMusic("breakfast.ogg");

    return true;
}

void Dialogue3::switchToCustomLayerButton(CCObject* object) {
    auto layer = Dialogue3::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

// Layer 7 Dialogue 4

Dialogue4* Dialogue4::create() {
    auto ret = new Dialogue4();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool Dialogue4::init() {

    auto DialoguePers1 = CCSprite::create("GDG_reporteroIcon_001.png");
    DialoguePers1->setPosition({86, 170});
    DialoguePers1->setScaleX({-1.2f});
    DialoguePers1->setScaleY({1.2f});
    addChild(DialoguePers1);

    DialoguePers1->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseExponentialInOut::create(CCMoveTo::create(1, {85, 170})), 
    CCEaseExponentialInOut::create(CCMoveTo::create(1, {130, 170})), nullptr)));

    auto DialogueSpr = CCSprite::create("DialogueButton.png");
    DialogueSpr->setPosition({289, 70});
    DialogueSpr->setScaleX({6.800f});
    DialogueSpr->setScaleY({1.500f});
    addChild(DialogueSpr);

    //Skip

    auto Skip = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Continuar", "bigFont.fnt"),
        this,
        menu_selector(LoadingSpr2::switchToCustomLayerButton)
    );

    Skip->setPosition({631, 74});

    auto DialogueMenu = CCMenu::create();
    DialogueMenu->addChild(Skip);
    DialogueMenu->setPosition(0, 0);
    DialogueMenu->setScale({0.5f});
    addChild(DialogueMenu);

    auto Texto1 = CCLabelBMFont::create("Reportero", "bigFont.fnt");
    Texto1->setPosition({115, 100});
    addChild(Texto1);

    auto Texto2 = CCLabelBMFont::create("GDGravity", "bigFont.fnt");
    Texto2->setPosition({245, 100});
    addChild(Texto2);

    Texto1->setScale({0.7f});
    Texto2->setScale({0.7f});

    Texto1->setOpacity(0.0f);
    Texto2->setOpacity(0.0f);

    Texto1->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2, 200), CCFadeTo::create(2, 200), nullptr)));
    Texto2->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.5, 200), CCFadeTo::create(2.5, 200), nullptr)));

    auto Flash = CCSprite::create("GJ_bigStar_glow_001.png");
    Flash->setPosition({284, 100});
    Flash->setZOrder(5);
    Flash->setScale(31.475f);
    addChild(Flash);

    Flash->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2, 0), CCFadeTo::create(2, 0), nullptr)));

    auto backgroundSprite = CCSprite::create("menuDialogue.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    gd::GameManager::sharedState()->fadeInMusic("breakfast2.ogg");

    return true;
}

void Dialogue4::switchToCustomLayerButton(CCObject* object) {
    auto layer = Dialogue4::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

// Layer 8 -> Loading Layer2

LoadingSpr2* LoadingSpr2::create() {
    auto ret = new LoadingSpr2();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool LoadingSpr2::init() {

    auto SkipButton = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Skip", "bigFont.fnt"),
        this,
        menu_selector(Level1::switchToCustomLayerButton)
    );

    SkipButton->setPosition({624, -110});
    SkipButton->setOpacity(0.0f);

    SkipButton->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2, 180), CCFadeTo::create(2, 180), nullptr)));

    auto LoadingMenuFNF = CCMenu::create();
    LoadingMenuFNF->addChild(SkipButton);
    LoadingMenuFNF->setPosition(0, 0);
    LoadingMenuFNF->setScale({0.475f});
    addChild(LoadingMenuFNF);

    ///Logo

    auto LogoMenu = CCSprite::create("FNF_logo.png");
    LogoMenu->setPosition({428, 220});
    LogoMenu->setScale({1.480f});
    addChild(LogoMenu);

    LogoMenu->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseExponentialInOut::create(CCScaleTo::create(1.1f, 1.15f)), 
    CCEaseExponentialInOut::create(CCScaleTo::create(0.5, 1.2f)), nullptr)));
    
    auto backgroundSprite = CCSprite::create("menuLoading.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    return true;
}


void LoadingSpr2::switchToCustomLayerButton(CCObject* object) {
    auto layer = LoadingSpr2::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

// Layer 9 Level 1

Level1* Level1::create() {
    auto ret = new Level1();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool Level1::init() {

    auto Personaje1 = CCSprite::create("GDG_reporteroIcon_002.png");
    Personaje1->setPosition({447, 74});
    Personaje1->setScaleX({-1.2f});
    Personaje1->setScaleY({1.2f});
    addChild(Personaje1);

    Personaje1->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseExponentialInOut::create(CCScaleTo::create(1.1f, 0.8f)), 
    CCEaseExponentialInOut::create(CCScaleTo::create(0.5, 0.5f)), nullptr)));

    auto Personaje2 = CCSprite::create("dialogIcon_002.png");
    Personaje2->setPosition({140, 74});
    addChild(Personaje2);

    Personaje2->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseExponentialInOut::create(CCScaleTo::create(1.1f, 1.0f)), 
    CCEaseExponentialInOut::create(CCScaleTo::create(0.5, 0.5f)), nullptr)));

    auto GameNote = CCSprite::create("Menu_NoteGame_001.png");
    GameNote->setPosition({285, 198});
    GameNote->setScale({1.213f});
    GameNote->setZOrder(6);
    addChild(GameNote);

    auto backgroundSprite3 = CCSprite::create("menuLevel1_002.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite3->getContentSize();

    backgroundSprite3->setScaleX(1.826f);
    backgroundSprite3->setScaleY(1.826f);

    backgroundSprite3->setAnchorPoint({0, 0});
    
    backgroundSprite3->setZOrder(5);
    backgroundSprite3->setPosition({-3.150, -7.810});
    addChild(backgroundSprite3);

    auto backgroundSprite = CCSprite::create("menuLevel1_001.png");

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);

    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setZOrder(-2);

    auto backgroundSprite2 = CCSprite::create("menuLevel1_003.png");

    backgroundSprite2->setScaleX(winSize.width / size.width);
    backgroundSprite2->setScaleY(winSize.height / size.height);

    backgroundSprite2->setAnchorPoint({0, 0});
    
    backgroundSprite2->setZOrder(-1);

    auto BackgroundMenu = CCMenu::create();
    BackgroundMenu->addChild(backgroundSprite);
    BackgroundMenu->addChild(backgroundSprite2);
    BackgroundMenu->setPosition(-4, 1.5);
    BackgroundMenu->setScale(1.679f);
    BackgroundMenu->setZOrder(-3);
    addChild(BackgroundMenu);

    gd::GameManager::sharedState()->fadeInMusic("level-1.mp3");

    auto regresarbutton = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(MenuSelectorTM::switchToCustomLayerButton)
    );

    auto menu1 = CCMenu::create();
    menu1->addChild(regresarbutton);
    
    menu1->setPosition({25, winSize.height - 25});

    menu1->setZOrder(7  );

    addChild(menu1);

    return true;
}

void Level1::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void Level1::switchToCustomLayerButton(CCObject* object) {
    auto layer = Level1::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

// Layer 10 -> CreditosLayer

CreditosLayer* CreditosLayer::create() {
    auto ret = new CreditosLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

void CreditosLayer::Creditos01(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "ToMorritow", "ok", nullptr, "Programador del Mod\n uwu");
    flalert->show();
}

void CreditosLayer::Creditos02(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "elSai", "ok", nullptr, "el quien me reto a hacer el mod\n unu");
    flalert->show();
}

void CreditosLayer::Creditos03(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "Edgajuman", "ok", nullptr, "Special Thanks");
    flalert->show();
}

void CreditosLayer::Creditos04(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "Jorgame", "ok", nullptr, "El quien me ayudo en hacer cositas\n o.o");
    flalert->show();
}

void LinksYTDS::Link1(CCObject* object) {
    LPCWSTR a = L"https://www.youtube.com/channel/UCJ73MdeBMcrLuSRE-A5TQqg";
    ShellExecuteW(NULL, L"open", a, NULL, NULL, SW_SHOWNORMAL);
}

void LinksYTDS::Link2(CCObject* object) {
    LPCWSTR a = L"https://discord.gg/THmJJ75Kcc";
    ShellExecuteW(NULL, L"open", a, NULL, NULL, SW_SHOWNORMAL);
}

void LinksYTDS::Link3(CCObject* object) {
    LPCWSTR a = L"https://www.youtube.com/@elsai5514";
    ShellExecuteW(NULL, L"open", a, NULL, NULL, SW_SHOWNORMAL);
}

void LinksYTDS::Link4(CCObject* object) {
    LPCWSTR a = L"https://www.youtube.com/@edgajuman2006";
    ShellExecuteW(NULL, L"open", a, NULL, NULL, SW_SHOWNORMAL);
}

void LinksYTDS::Link5(CCObject* object) {
    LPCWSTR a = L"https://www.youtube.com/@JorGameGD";
    ShellExecuteW(NULL, L"open", a, NULL, NULL, SW_SHOWNORMAL);
}

void LinksYTDS::Link6(CCObject* object) {
    LPCWSTR a = L"https://discord.gg/EZkCf3pEmQ";
    ShellExecuteW(NULL, L"open", a, NULL, NULL, SW_SHOWNORMAL);
}

bool CreditosLayer::init() {

    auto Creditos1 = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("ToMorritow", "bigFont.fnt"),
        this,
        menu_selector(CreditosLayer::Creditos01)
    );

    Creditos1->setPosition({100, 100});

    auto Creditos2 = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("elSai", "bigFont.fnt"),
        this,
        menu_selector(CreditosLayer::Creditos02)
    );

    Creditos2->setPosition({100, 65});

    auto Creditos3 = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Edgajuman", "bigFont.fnt"),
        this,
        menu_selector(CreditosLayer::Creditos03)
    );

    Creditos3->setPosition({100, 25});

    auto Creditos4 = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Jorgame", "bigFont.fnt"),
        this,
        menu_selector(CreditosLayer::Creditos04)
    );

    Creditos4->setPosition({100, -15});

    //Links

    auto Links1 = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png"),
        this,
        menu_selector(LinksYTDS::Link1)
    );

    Links1->setPosition({218, 98});
    Links1->setScale({1.150f});

    auto Links2 = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png"),
        this,
        menu_selector(LinksYTDS::Link2)
    );

    Links2->setPosition({256, 98});
    Links2->setScale({1.150f});

    auto Links3 = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png"),
        this,
        menu_selector(LinksYTDS::Link3)
    );

    Links3->setPosition({168, 62});
    Links3->setScale({1.150f});

    auto Links4 = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png"),
        this,
        menu_selector(LinksYTDS::Link4)
    );

    Links4->setPosition({208, 22});
    Links4->setScale({1.150f});

    auto Links5 = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png"),
        this,
        menu_selector(LinksYTDS::Link5)
    );

    Links5->setPosition({191, -18.300});
    Links5->setScale({1.150f});

    auto Links6 = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png"),
        this,
        menu_selector(LinksYTDS::Link6)
    );

    Links6->setPosition({293, 98});
    Links6->setScale({1.150f});

    auto menu2 = CCMenu::create();
    menu2->addChild(Creditos1);
    menu2->addChild(Creditos2);
    menu2->addChild(Creditos3);
    menu2->addChild(Creditos4);
    menu2->addChild(Links1);
    menu2->addChild(Links2);
    menu2->addChild(Links3);
    menu2->addChild(Links4);
    menu2->addChild(Links5);
    menu2->addChild(Links6);
    menu2->setPosition(-52, 84);
    menu2->setScale({0.525f});
    addChild(menu2);

    ///Logo

    auto LogoMenu = CCSprite::create("FNF_logo.png");
    LogoMenu->setPosition({428, 220});
    LogoMenu->setScale({1.480f});
    addChild(LogoMenu);

    LogoMenu->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseExponentialInOut::create(CCScaleTo::create(1.1f, 1.15f)), 
    CCEaseExponentialInOut::create(CCScaleTo::create(0.5, 1.2f)), nullptr)));
    
    auto backgroundSprite = CCSprite::create("menuDesat.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});

    backgroundSprite->setColor({100, 100, 100});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto regresarbutton = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(LayerListFNF::switchToCustomLayerButton)
    );

    auto menu1 = CCMenu::create();
    menu1->addChild(regresarbutton);
    
    menu1->setPosition({25, winSize.height - 25});

    menu1->setZOrder(7  );

    addChild(menu1);

    return true;
}

void CreditosLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void CreditosLayer::switchToCustomLayerButton(CCObject* object) {
    auto layer = CreditosLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

const char* ToMorritow = "CodigoDeSai";