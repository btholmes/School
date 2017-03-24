#ifndef USER_H
# define USER_H

# include <stdint.h>
# include <vector>
# include <string>

class User{
	
	private: 
		std::string name, password; 
		int highScore, gamesWon; 

	public: 
		User() : name(), password(), highScore(0),  gamesWon(0)
		{

		} 
		
		void setPass(const std::string &name, const std::string &password); 

		void setHighScore(const int score)
		{
			hgihScore = score; 
		} 
		
		void setGamesWon(const int wins)
		{
			gamesWon = wins; 
		}
			
}
