// Scene.hpp

#include "Scene.hpp"

Scene::~Scene()
{
    mEntities.clear();
}

Entity& Scene::CreateEntity()
{
    Entity entity;
    entity.SetParentRegistry(&mRegistry);
    entity.mID = mEntities.size();
    mRegistry.Transforms[entity.mID] = Transform2D();

    mEntities.push_back(entity);
    return mEntities.back();
}

void Scene::DestroyEntity(const Entity& e)
{
    for (size_t i = 0; i < mEntities.size(); i++) {
        if (mEntities[i].mID == e.mID) {
            mEntities.erase(mEntities.begin() + i);
            break;
        } 
    }
}

void Scene::Update(float dt)
{
    mTransformSystem.Update(mRegistry, dt, mEntities.size());
    mColliderSystem.Update(mRegistry, mEntities.size());
}

void Scene::Render(sf::RenderWindow& target)
{
    mColliderSystem.Draw(mRegistry, mEntities.size(), target);
    mCircleSystem.Update(mRegistry, mEntities.size(), target);
    mRectangleSystem.Update(mRegistry, mEntities.size(), target);
}
