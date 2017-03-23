#ifndef HACKING_MODEL_H_
#define HACKING_MODEL_H_

#include <vector>
#include <string>
#include <Windows.h>

class PuzzleWord;

class HackingModel
{
public:
	HackingModel();
	~HackingModel();

	int GetAttemptsRemaining() const;

	const std::string& GetHexAddress(int index) const;

	const unsigned int GetPuzzleWordCount() const;
	const unsigned int GetAttemptedWordCount() const;

	PuzzleWord * const GetPuzzleWord(int index) const;
	PuzzleWord* const GetSelectedPuzzleWord() const;

	void OnClickEvent();
	void OnMouseMoveEvent(COORD cursorCoord);

private:
	int attemptsRemaining;

	std::vector<std::string> hexAddresses;

	std::string solutionWord;
	std::vector<PuzzleWord*> puzzleWords;
	std::vector<std::string> attemptedWords;

	PuzzleWord* currentHighlightedPuzzleWord;

	void SetHexAddresses();
	void SetPuzzleWords();
	void PlacePuzzleWords();
	void GetSampleWordList(std::vector<std::string>& _out);
};

#endif