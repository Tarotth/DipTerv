float4 mainVP(float4 pos : SV_POSITION, uniform float4x4 worldViewProj_m) : SV_Position
{
	// This keeps the object in place by multiplying the world view projection matrix by the position.
	return mul(worldViewProj_m, pos);
}