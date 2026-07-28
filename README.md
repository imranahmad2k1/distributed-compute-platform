# Mini Compute Platform

A small distributed compute platform built from scratch in C/C++: a control
node dispatches commands and jobs to a fleet of worker nodes over a custom
TCP protocol, tracks worker health via heartbeats, schedules and retries
jobs on failure, and exposes metrics for observability.

The goal is to learn systems/infrastructure engineering fundamentals by
building the pieces most frameworks hide: sockets, process control,
protocol design, scheduling, failure detection, and performance profiling
on real Linux VMs.

## Architecture (early sketch)

- **Control node** — accepts commands, fans them out to workers, runs the
  job scheduler, tracks worker liveness, exposes metrics.
- **Worker agents** — long-running process on each worker VM that listens
  on a TCP port, executes commands/jobs, and reports back health/stats.
- **Protocol** — text-based command protocol for v1 (`health`, `stats`,
  `run <command>`), designed to evolve as jobs/scheduling are added.

Infrastructure: 1 control VM + 2 worker VMs (Vultr), Linux, connected over
SSH for provisioning/deployment and over the custom TCP protocol at runtime.

## Status

Early days — see `docs/` for design notes as they're written. This README
will be filled in with build/run instructions once the first components
exist.

## Repo layout

- `src/` — source files
- `include/` — headers
- `scripts/` — setup/deploy/benchmark helper scripts
- `docs/` — architecture, protocol, and design notes
- `benchmarks/` — benchmark results and notes
