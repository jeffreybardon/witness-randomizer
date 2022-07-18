#pragma once
#include "Generate.h"
#include "Special.h"
#include "Random.h"

class PuzzleList {

public: 

	void GenerateAllN();
	void GenerateAllH();
	void GenerateAllE();

	PuzzleList() {
		generator = std::make_shared<Generate>();
		specialCase = std::make_shared<Special>(generator);
	}

	PuzzleList(std::shared_ptr<Generate> generator) {
		this->generator = generator;
		this->specialCase = std::make_shared<Special>(generator);
	}

	void setLoadingHandle(HWND handle) {
		_handle = handle;
		generator->setLoadingHandle(handle);
	}

	void setSeed(int seed, bool isRNG, bool colorblind) {
		this->seed = seed;
		this->seedIsRNG = isRNG;
		this->colorblind = colorblind;
		if (seed >= 0) generator->seed(seed);
		else generator->seed(Random::rand());
		generator->colorblind = colorblind;
	}

	void CopyTargets();

	//--------------------------Normal difficulty---------------------------

	void GenerateTutorialN();
	void GenerateSymmetryN();
	void GenerateQuarryN();
	void GenerateBunkerN(); //Can't randomize because panels refuse to render the symbols
	void GenerateSwampN();
	void GenerateTreehouseN();
	void GenerateTownN();
	void GenerateVaultsN();
	void GenerateTrianglePanelsN();
	void GenerateMountainN();
	void GenerateCavesN();

	//Environmental areas - unless I can figure out how to mess with the game's assets, randomizing most of these puzzles isn't happening anytime soon
	void GenerateOrchardN();
	void GenerateDesertN(); //Just scramble the positions for now
	void GenerateShadowsN(); //Can't randomize
	void GenerateKeepN();
	void GenerateMonasteryN(); //Can't randomize
	void GenerateJungleN();

	//-------------------------Hard difficulty--------------------------

	void GenerateTutorialH();
	void GenerateSymmetryH();
	void GenerateQuarryH();
	void GenerateBunkerH();
	void GenerateSwampH();
	void GenerateTreehouseH();
	void GenerateTownH();
	void GenerateVaultsH();
	void GenerateTrianglePanelsH();
	void GenerateMountainH();
	void GenerateCavesH();

	//Environmental areas - unless I can figure out how to mess with the game's assets, randomizing some of these puzzles isn't happening anytime soon
	void GenerateOrchardH();
	void GenerateDesertH(); //Just scramble the positions for now
	void GenerateShadowsH(); //Can't randomize
	void GenerateKeepH();
	void GenerateMonasteryH(); //Can't randomize
	void GenerateJungleH();

//--------------------------Easy difficulty---------------------------

	void GenerateTutorialE();
	void GenerateSymmetryE();
	void GenerateQuarryE();
	void GenerateBunkerE(); //Can't randomize because panels refuse to render the symbols
	void GenerateSwampE();
	void GenerateTreehouseE();
	void GenerateTownE();
	void GenerateVaultsE();
	void GenerateTrianglePanelsE();
	void GenerateMountainE();
	void GenerateCavesE();

	//Environmental areas - unless I can figure out how to mess with the game's assets, randomizing most of these puzzles isn't happening anytime soon
	void GenerateOrchardE();
	void GenerateDesertE(); //Just scramble the positions for now
	void GenerateShadowsE(); //Can't randomize
	void GenerateKeepE();
	void GenerateMonasteryE(); //Can't randomize
	void GenerateJungleE();

private:
	std::shared_ptr<Generate> generator;
	std::shared_ptr<Special> specialCase;
	HWND _handle = nullptr;
	int seed = 0;
	bool seedIsRNG = false;
	bool colorblind = false;

	template <class T> T pick_random(std::vector<T>& vec) { return vec[Random::rand() % vec.size()]; }
	template <class T> T pick_random(std::set<T>& set) { auto it = set.begin(); std::advance(it, Random::rand() % set.size()); return *it; }
	template <class T> T pop_random(std::vector<T>& vec) {
		int i = Random::rand() % vec.size();
		T item = vec[i];
		vec.erase(vec.begin() + i);
		return item;
	}
	template <class T> T pop_random(std::set<T>& set) {
		auto it = set.begin();
		std::advance(it, Random::rand() % set.size());
		T item = *it;
		set.erase(item);
		return item;
	}
};