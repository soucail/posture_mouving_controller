set(controller_SRC
  PostureMouvingController.cpp
)

set(controller_HDR
  PostureMouvingController.h
)

add_controller(${PROJECT_NAME} ${controller_SRC} ${controller_HDR})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-DPostureMouvingController_EXPORTS")

