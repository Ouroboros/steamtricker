#ifndef STEAMTRICKER_STEAMAPI_CLIENT_H_
#define STEAMTRICKER_STEAMAPI_CLIENT_H_

#include "apps.h"
#include "friends.h"
#include "gameserver.h"
#include "masterserverupdater.h"
#include "remotestorage.h"
#include "networking.h"
#include "matchmaking.h"
#include "user.h"
#include "userstats.h"
#include "utils.h"

#include "types.h"

class ISteamClient {
public:
	virtual SteamPipeId CreateSteamPipe() = 0;

	virtual bool BReleaseSteamPipe(SteamPipeId steamPipe) = 0;

	virtual SteamUserId ConnectToGlobalUser(SteamPipeId steamPipe) = 0;

	virtual SteamUserId CreateLocalUser(SteamPipeId *steamPipe, AccountType accountType) = 0;

	virtual void ReleaseUser(SteamPipeId steamPipe, SteamUserId user) = 0;

	virtual ISteamUser *GetISteamUser(SteamUserId steamUser,
				  SteamPipeId steamPipe,
				  const char *version) = 0;

	virtual ISteamGameServer *GetISteamGameServer(SteamUserId steamUser,
					      SteamPipeId steamPipe,
					      const char *version) = 0;

	virtual void SetLocalIPBinding(uint32 ip, uint16 port) = 0;

	virtual ISteamFriends *GetISteamFriends(SteamUserId steamUser,
					SteamPipeId steamPipe,
					const char *version) = 0;

	virtual ISteamUtils *GetISteamUtils(SteamPipeId steamPipe, const char *version) = 0;

	virtual ISteamMatchmaking *GetISteamMatchmaking(SteamUserId steamUser,
						SteamPipeId steamPipe,
						const char *version) = 0;

	virtual ISteamMasterServerUpdater *GetISteamMasterServerUpdater(
		SteamUserId steamUser,
		SteamPipeId steamPipe,
		const char *version) = 0;

	virtual ISteamMatchmakingServers *GetISteamMatchmakingServers(
		SteamUserId steamUser,
		SteamPipeId steamPipe,
		const char *version) = 0;

	virtual void *GetISteamGenericInterface(SteamUserId steamUser,
					SteamPipeId steamPipe,
					const char *version) = 0;

	virtual ISteamUserStats *GetISteamUserStats(SteamUserId steamUser,
					    SteamPipeId steamPipe,
					    const char *version) = 0;

	virtual ISteamGameServerStats *GetISteamGameServerStats(SteamUserId steamUser,
							SteamPipeId steamPipe,
							const char *version) = 0;

	virtual ISteamApps *GetISteamApps(SteamUserId steamUser,
				  SteamPipeId steamPipe,
				  const char *version) = 0;

	virtual ISteamNetworking *GetISteamNetworking(SteamUserId steamUser,
					      SteamPipeId steamPipe,
					      const char *version) = 0;

	virtual ISteamRemoteStorage *GetISteamRemoteStorage(SteamUserId steamUser,
						    SteamPipeId steamPipe,
						    const char *version) = 0;

	virtual void RunFrame() = 0;

	virtual uint32 GetIPCCallCount() = 0;

	virtual void SetWarningMessageHook(SteamAPIWarningMessageHook function) = 0;

};

class CSteamClient : public ISteamClient {
public:
	static CSteamClient& getInstance() {
		static CSteamClient instance;
		return instance;
	}

	SteamPipeId CreateSteamPipe();

	bool BReleaseSteamPipe(SteamPipeId steamPipe);

	SteamUserId ConnectToGlobalUser(SteamPipeId steamPipe);

	SteamUserId CreateLocalUser(SteamPipeId *steamPipe, AccountType accountType);

	void ReleaseUser(SteamPipeId steamPipe, SteamUserId user);

	ISteamUser *GetISteamUser(SteamUserId steamUser,
				  SteamPipeId steamPipe,
				  const char *version);

	ISteamGameServer *GetISteamGameServer(SteamUserId steamUser,
					      SteamPipeId steamPipe,
					      const char *version);

	void SetLocalIPBinding(uint32 ip, uint16 port);

	ISteamFriends *GetISteamFriends(SteamUserId steamUser,
					SteamPipeId steamPipe,
					const char *version);

	ISteamUtils *GetISteamUtils(SteamPipeId steamPipe, const char *version);

	ISteamMatchmaking *GetISteamMatchmaking(SteamUserId steamUser,
						SteamPipeId steamPipe,
						const char *version);

	ISteamMasterServerUpdater *GetISteamMasterServerUpdater(
		SteamUserId steamUser,
		SteamPipeId steamPipe,
		const char *version);

	ISteamMatchmakingServers *GetISteamMatchmakingServers(
		SteamUserId steamUser,
		SteamPipeId steamPipe,
		const char *version);

	void *GetISteamGenericInterface(SteamUserId steamUser,
					SteamPipeId steamPipe,
					const char *version);

	ISteamUserStats *GetISteamUserStats(SteamUserId steamUser,
					    SteamPipeId steamPipe,
					    const char *version);

	ISteamGameServerStats *GetISteamGameServerStats(SteamUserId steamUser,
							SteamPipeId steamPipe,
							const char *version);

	ISteamApps *GetISteamApps(SteamUserId steamUser,
				  SteamPipeId steamPipe,
				  const char *version);

	ISteamNetworking *GetISteamNetworking(SteamUserId steamUser,
					      SteamPipeId steamPipe,
					      const char *version);

	ISteamRemoteStorage *GetISteamRemoteStorage(SteamUserId steamUser,
						    SteamPipeId steamPipe,
						    const char *version);

	void RunFrame();

	uint32 GetIPCCallCount();

	void SetWarningMessageHook(SteamAPIWarningMessageHook function);

};

#endif /* STEAMTRICKER_STEAMAPI_CLIENT_H_ */