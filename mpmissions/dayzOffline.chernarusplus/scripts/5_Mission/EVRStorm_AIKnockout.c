modded class EVRStorm
{
	override void EndPhaseServer()
	{
		Print("[EVR-AI] EndPhaseServer called - starting AI knockout");
		super.EndPhaseServer();

		array<Object> objects = new array<Object>();
		GetGame().GetObjectsInRadius(Vector(7200, 0, 7200), 12000, objects);
		Print("[EVR-AI] Objects found in radius: " + objects.Count());

		int aiCount = 0;
		int aiKnocked = 0;
		foreach (Object obj : objects)
		{
			eAIBase ai = eAIBase.Cast(obj);
			if (!ai)
				continue;

			aiCount++;
			if (!ai.IsAlive())
				continue;

			ai.SetHealth("", "Shock", 0.0);
			aiKnocked++;
			Print("[EVR-AI] Knocked out AI: " + ai.GetType() + " at " + ai.GetPosition());
		}

		Print("[EVR-AI] AI total found: " + aiCount + " | knocked out: " + aiKnocked);
	}
}
