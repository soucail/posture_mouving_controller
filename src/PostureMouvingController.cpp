#include "PostureMouvingController.h"

PostureMouvingController::PostureMouvingController(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::MCController(rm, dt)
{
  solver().addConstraintSet(contactConstraint);
  solver().addConstraintSet(kinematicsConstraint);
  solver().addTask(postureTask);
  solver().setContacts({{}});

  mc_rtc::log::success("PostureMouvingController init done ");
}

bool PostureMouvingController::run()
{
  return mc_control::MCController::run();
}

void PostureMouvingController::reset(const mc_control::ControllerResetData & reset_data)
{
  mc_control::MCController::reset(reset_data);
}

CONTROLLER_CONSTRUCTOR("PostureMouvingController", PostureMouvingController)
