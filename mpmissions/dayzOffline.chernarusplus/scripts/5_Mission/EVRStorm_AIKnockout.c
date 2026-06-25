modded class EVRStorm
{
	override void EndPhaseServer()
	{
		super.EndPhaseServer();

		array<Object> objects = new array<Object>();
		GetGame().GetObjectsInRadius(Vector(7200, 0, 7200), 12000, objects);

		foreach (Object obj : objects)
		{
			eAIBase ai = eAIBase.Cast(obj);
			if (!ai || !ai.IsAlive())
				continue;

			ai.SetHealth("", "Shock", 0.0);
		}
	}
}
