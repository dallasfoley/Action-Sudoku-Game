Project(GameLib)

set(SOURCE_FILES
        GameView.cpp
        GameView.h
        pch.h
        MainFrame.cpp
        MainFrame.h
        Game.cpp
        Game.h
        Sparty.cpp
        Sparty.h
        Item.cpp
        Item.h
        Board.cpp
        Board.h
        XRay.cpp
        XRay.h
        Level.cpp
        Level.h
        Number.cpp
        Number.h
        ids.h
        Scoreboard.cpp
        Scoreboard.h
        Declaration.cpp
        Declaration.h
        SpeedPotion.cpp
        SpeedPotion.h
        Container.cpp
        Container.h
        DeclarationNumber.cpp
        DeclarationNumber.h
        DeclarationSparty.cpp
        DeclarationSparty.h
        DeclarationContainer.cpp
        DeclarationContainer.h
        DeclarationXray.cpp
        DeclarationXray.h
        FpsDisplay.cpp
        FpsDisplay.h
        CheckIsContainerVisitor.cpp
        CheckIsContainerVisitor.h
        ItemVisitor.cpp
        ItemVisitor.h
        CheckIsNumberVisitor.cpp
        CheckIsNumberVisitor.h
        CheckIsXRayVisitor.cpp
        CheckIsXRayVisitor.h
        CheckIsPotionVisitor.cpp
        CheckIsPotionVisitor.h
        DeclarationPotion.cpp
        DeclarationPotion.h)


set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)