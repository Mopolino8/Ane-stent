#ifndef SCENE_RIGID_OBJECT_H
#define SCENE_RIGID_OBJECT_H

#include <chrono>
#include <memory>
#include <string>

#include <BulletSoftBody/btSoftBody.h>
#include <btBulletDynamicsCommon.h>

#include <vtkActor.h>
#include <vtkSmartPointer.h>
#include <vtkTransform.h>

/**
 * @brief Contiene la información necesaria para simular la física de un objeto
 * Bullet y renderizarlo con VTK.
 */
class SceneRigidObject : public std::enable_shared_from_this<SceneRigidObject> {
public:
  std::string name;
  vtkSmartPointer<vtkActor> actor;
  std::shared_ptr<btCollisionShape> collider;
  std::shared_ptr<btMotionState> motionState;
  std::shared_ptr<btRigidBody> rigidBody;

  SceneRigidObject(vtkSmartPointer<vtkActor> actor,
                   std::shared_ptr<btCollisionShape> collider);
  SceneRigidObject(vtkSmartPointer<vtkActor> actor,
                   std::shared_ptr<btCollisionShape> collider,
                   std::shared_ptr<btRigidBody> rigidBody);

  ~SceneRigidObject();
  void InitRigidBody(btScalar mass = 1,
                     vtkSmartPointer<vtkTransform> transform =
                         vtkSmartPointer<vtkTransform>::New());
  virtual void UpdatePhysics(std::chrono::duration<double> deltaTime);
  btVector3 GetCenterOfGeometry();
};
#endif