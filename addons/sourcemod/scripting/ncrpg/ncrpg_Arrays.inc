void CreateSkillsArray()
{
	if(hArraySkills != null)
	{
		ResetSkillCount();
		hArraySkills.Close();
	}
	
	if((hArraySkills = CreateArray()) == null)
		NCRPg_LogPrint(LogType_Error, "Could not create an array of skills");
}

int GetSkillArrayPosition(int skillid) {
	if(IsValidSkillID(skillid))
	{
		int aSize = GetArraySize(hArraySkills);
		for(int pos = 0; pos < aSize; ++pos)
            if(skillid == GetArrayCell(GetArrayCell(hArraySkills, pos), ARR_SKILL_ID))
                return pos;
	}
	return -1;
}

int GetPlayerArrayPosition(int client) {
	int aSize = GetArraySize(hArrayPlayers);
	for(int pos = 0; pos < aSize; ++pos)
	{
		if(client == GetArrayCell(GetArrayCell(hArrayPlayers, pos), ARR_PLAYER_INDEX))
			return pos;
	}
	
	return -1;
}

void CreatePlayersArray() {
	if(hArrayPlayers != null) hArrayPlayers.Close();
	
	if((hArrayPlayers = CreateArray()) == null)
		NCRPg_LogPrint(LogType_FailState, "Could not create an array of players");
		
	LoadAllPlayers();
}
