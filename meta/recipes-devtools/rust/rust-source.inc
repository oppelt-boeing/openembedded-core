RUST_VERSION ?= "${@d.getVar('PV').split('-')[0]}"

SRC_URI += "https://static.rust-lang.org/dist/rustc-${RUST_VERSION}-src.tar.xz;name=rust \
            file://hardcodepaths.patch;patchdir=${RUSTSRC} \
            file://zlib-off64_t.patch;patchdir=${RUSTSRC} \
            file://0001-Revert-Map-source-absolute-paths-to-OUT_DIR-as-relat.patch;patchdir=${RUSTSRC} \
            file://rv32-rustix-libc-backend.patch;patchdir=${RUSTSRC} \
            file://rv32-cargo-rustix-0.38.19-fix.patch;patchdir=${RUSTSRC} \
            file://repro-issue-fix-with-v175.patch;patchdir=${RUSTSRC} \
            file://0001-cargo-do-not-write-host-information-into-compilation.patch;patchdir=${RUSTSRC} \
            file://rustdoc-repro-issue-fix-cargo-config-for-codegenunits.patch;patchdir=${RUSTSRC} \
            file://cross-targets-backport.patch;patchdir=${RUSTSRC} \
            file://deadcode-backport.patch;patchdir=${RUSTSRC} \
            file://rust-oe-selftest.patch;patchdir=${RUSTSRC} \
            file://repro-issue-fix-with-cc-crate-hashmap.patch;patchdir=${RUSTSRC} \
"
SRC_URI[rust.sha256sum] = "4d214c4189e4dd934d47e869fa5721b2c33dbbbdea21f2fc7fa6df3f38c1dea2"

RUSTSRC = "${WORKDIR}/rustc-${RUST_VERSION}-src"

UPSTREAM_CHECK_URI = "https://forge.rust-lang.org/infra/other-installation-methods.html"
UPSTREAM_CHECK_REGEX = "rustc-(?P<pver>\d+(\.\d+)+)-src"

CVE_STATUS[CVE-2024-24576] = "not-applicable-platform: Issue only applies on Windows"
