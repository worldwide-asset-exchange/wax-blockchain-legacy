# How to use EOS Studio with WAX

This is a simple guide to provide a minimal integration between WAX and [EOS Studio](https://www.eosstudio.io/).

Requirements:

- Docker (configured to run without sudo)

Disclaimer: This guide was developed/tested with Ubuntu 18.04

## Prepare EOS studio for WAX

Execute the following:

```
$ wax-blockchain/samples/eos-studio/prepare-eosstudio-for-wax.sh
```

The script is going to download *wax-system-contracts* and *WAX development docker image*, after that it will prepare them for their use by EOS Studio.

## Get EOS Studio

Download EOS Studio from https://www.eosstudio.io/

After download, prepare the binary for execution:

```
$ chmod +x <download directory>/EOSStudio-x.y.z.AppImage
```

Note: **x.y.z** is the EOS Studio current version.

And finally execute it:

```
$ <download directory>/EOSStudio-x.y.z.AppImage
```

