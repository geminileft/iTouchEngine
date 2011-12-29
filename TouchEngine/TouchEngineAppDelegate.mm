#import "TouchEngineAppDelegate.h"

#include "FreeCellGame.h"

@implementation TouchEngineAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    mGame = new FreeCellGame(320, 480);
    mGame->initialize();
    return YES;
}

- (void)dealloc
{
    delete mGame;
    [super dealloc];
}

@end
