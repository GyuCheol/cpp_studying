#include "Game.h"

namespace lab9
{
	Game::Game(unsigned int seed, unsigned int poolSize)
	{
		mPool = new ObjectPool<IceCube>(poolSize);
		srand(seed);
	}

	Game::~Game()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end(); ++it)
		{
			delete (*it);
		}

		delete mPool;
		mActiveGameObjects.clear();
	}

	void Game::Spawn()
	{
		IceCube* iceCube = mPool->Get();

		iceCube->Initialize(rand() % MAX_FRAME_COUNT_TO_LIVE + 1);
		mActiveGameObjects.push_back(iceCube);
	}

	void Game::Update()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end();)
		{
			IceCube* iceCube = *it;
			iceCube->Animate();

			if (!iceCube->IsActive())
			{
				it = mActiveGameObjects.erase(it);
				mPool->Return(iceCube);
				continue;
			}

			++it;
		}
	}

	const std::vector<IceCube*>& Game::GetActiveGameObjects() const
	{
		return mActiveGameObjects;
	}
	ObjectPool<IceCube>& Game::GetObjectPool()
	{
		return *mPool;
	}
}