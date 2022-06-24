if tup.getconfig("NO_GCC") ~= "" then return end
if tup.getconfig("HELPERDIR") == ""
then
  HELPERDIR = "../../../programs"
end
tup.include(HELPERDIR .. "/use_gcc.lua")
tup.include(HELPERDIR .. "/use_newlib.lua")
tup.include(HELPERDIR .. "/use_sdl_newlib.lua")
tup.include(HELPERDIR .. "/use_sound.lua")

CFLAGS = CFLAGS_OPTIMIZE_SPEED .. " -D_SDL -DUSE_SDL=1 -DCM_USE_STB_VORBIS "
LDFLAGS = LDFLAGS .. " --subsystem=native  "

compile_gcc{
    "src/collision.c",
    "src/effect.c",
    "src/enemy.c",
    "src/game.c",
    "src/hero.c",
    "src/ini.c",
    "src/inventory.c",
    "src/main.c",
    "src/object.c",
    "src/options.c",
    "src/PHL.c",
    "src/platform.c",
    "src/qda.c",
    "src/stagedata.c",
    "src/text.c",
    "src/titlescreen.c",
    "src/weapon.c",
    "src/enemies/batboss.c",
    "src/enemies/bat.c",
    "src/enemies/bee.c",
    "src/enemies/boar.c",
    "src/enemies/boomknight.c",
    "src/enemies/crab.c",
    "src/enemies/devil.c",
    "src/enemies/dodo.c",
    "src/enemies/dog.c",
    "src/enemies/firewheel.c",
    "src/enemies/fish.c",
    "src/enemies/garm.c",
    "src/enemies/gas.c",
    "src/enemies/ghoul.c",
    "src/enemies/golem.c",
    "src/enemies/gyra.c",
    "src/enemies/heads.c",
    "src/enemies/hydra.c",
    "src/enemies/jellyfish.c",
    "src/enemies/knight.c",
    "src/enemies/lolidra.c",
    "src/enemies/pendulum.c",
    "src/enemies/podoboo.c",
    "src/enemies/poisonknight.c",
    "src/enemies/pumpkin.c",
    "src/enemies/seal.c",
    "src/enemies/skeleton.c",
    "src/enemies/skull.c",
    "src/enemies/slime.c",
    "src/enemies/slug.c",
    "src/enemies/thwomp.c",
    "src/enemies/waterjumper.c",
    "src/enemies/wizard.c",
    "src/misc.c"
}

compile_gcc{
    "src/sdl/audio.c",
    "src/sdl/input.c",
    "src/sdl/graphics.c",
    "src/sdl/system.c",
    "src/sdl/joystick_stub.c"
}

compile_gcc {
    "src/cmixer/cmixer.c",
    "src/cmixer/stb_vorbis.c"
}

link_gcc("hcl")
