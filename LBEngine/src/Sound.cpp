#include "pch.h"
#include "Sound.h"

#include "Game.h"
#include "Scene.h"

using namespace DirectX;

void Sound::Stop(bool immediate)
{
	m_soundEffectInstance->Stop(immediate);
}

void Sound::Pause()
{
	m_soundEffectInstance->Pause();
}

void Sound::Resume()
{
	m_soundEffectInstance->Resume();
}

Sound::Sound()
{
	
}

Sound::Sound(const wchar_t* waveFileName)
{
	auto& game = Game::GetInstance();

	m_soundEffect = std::make_unique<SoundEffect>(game.m_audEngine.get(), waveFileName);
	m_soundEffectInstance = m_soundEffect->CreateInstance();
}

Sound::~Sound()
{
	m_soundEffectInstance.reset();
}

void Sound::Play(bool loop)
{
	m_soundEffectInstance->Play(loop);
	if (loop)
	{
		auto& game = Game::GetInstance();
		auto pScene = game.GetScene();
		pScene->AddLoopedSound(this);
	}
}

void Sound::SetVolume(float volume)
{
	m_soundEffectInstance->SetVolume(volume);
}

void Sound::SetPitch(float pitch)
{
	m_soundEffectInstance->SetPitch(pitch);
}

void Sound::SetPan(float pan)
{
	m_soundEffectInstance->SetPan(pan);
}
